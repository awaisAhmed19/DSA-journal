import os
import json
import re
from dotenv import load_dotenv
import google.generativeai as genai

# ----------------------------
# ENV + API CONFIG
# ----------------------------
load_dotenv()
API_KEY = os.getenv("GEMINI_API_KEY")
MODEL_NAME = "gemini-2.0-flash"
if not API_KEY:
    raise ValueError(
        "Missing Gemini API key. Add it to your .env file as GEMINI_API_KEY.")

genai.configure(api_key=API_KEY)

# Initialize the Gemini model
model = genai.GenerativeModel(MODEL_NAME)


# ----------------------------
# PROMPT SYSTEM
# ----------------------------
def load_prompt_template(prompt_type: str) -> str:
    """
    Load base prompt (resume or cover) from backend/templates/
    """
    base_path = os.path.join(os.path.dirname(__file__), "templates")
    file_path = os.path.join(base_path, f"{prompt_type}_prompt.txt")

    if not os.path.exists(file_path):
        raise FileNotFoundError(f"Prompt file not found: {file_path}")

    with open(file_path, "r") as f:
        return f.read().strip()


def build_prompt(prompt_type: str, user_data: dict) -> str:
    """
    Merge user input data and base LaTeX template into one structured prompt.
    """
    base_path = os.path.join(os.path.dirname(__file__), "templates")
    latex_template_path = os.path.join(base_path, "resume_templates.tex")
    prompt_template_path = os.path.join(base_path, f"{prompt_type}_prompt.txt")

    # Load files
    with open(latex_template_path, "r") as f:
        latex_template = f.read().strip()

    with open(prompt_template_path, "r") as f:
        prompt_template = f.read().strip()

    # Merge user JSON and template into the prompt
    user_json = json.dumps(user_data, indent=2)

    prompt = (
        prompt_template
        .replace("{{ TEMPLATE_CONTENT }}", latex_template)
        .replace("{{ USER_DATA }}", user_json)
    )

    return prompt


# ----------------------------
# CORE GEMINI CALL
# ----------------------------
def clean_latex_output(raw: str) -> str:
    """
    Extract LaTeX code from a markdown-style block if present.
    """
    match = re.search(r"```latex\s*(.*?)```", raw, re.DOTALL)
    if match:
        return match.group(1).strip()
    return raw.strip()


def generate_latex(prompt: str) -> str:
    response = model.generate_content(prompt)
    text = response.candidates[0].content.parts[0].text
    cleaned = clean_latex_output(text)

    if not cleaned.startswith("\\documentclass"):
        raise ValueError("Gemini did not return valid LaTeX output.")

    return cleaned
# ----------------------------
# LOCAL TEST MODE
# ----------------------------
# EXAMPLE RUN
# ----------------------------
# if __name__ == "__main__":
#    sample_data = {
#        "name": "Awais Khan",
#        "skills": ["Python", "C++", "AI Research"],
#        "goal": "Get an ML internship"
#    }

#   dry_run("resume", sample_data)
