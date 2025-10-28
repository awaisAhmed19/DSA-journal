from flask import Flask, request, jsonify, send_file, send_from_directory
from flask_cors import CORS
from dotenv import load_dotenv
import os
import json
import traceback  # Import traceback here for general use
from gemini_client import build_prompt, generate_latex
# Assuming these modules are defined elsewhere in your project:
from latex_compiler import compile_latex_to_pdf
# from gemini_client import build_prompt, generate_latex
# from latex_compiler import compile_latex_to_pdf

# Load environment variables (e.g., Gemini API key)
load_dotenv()

# --- Configuration ---
# Adjust this path based on your project structure
FRONTEND_DIR = os.path.join(os.path.dirname(__file__), "../frontend")
OUTPUT_DIR = os.path.join(os.path.dirname(__file__), "outputs")
os.makedirs(OUTPUT_DIR, exist_ok=True)
# ---------------------

app = Flask(
    __name__,
    static_folder=FRONTEND_DIR,
    static_url_path=""
)

CORS(app)


@app.route("/api/generate", methods=["POST"])
def generate():
    data = request.get_json(silent=True) or {}
    prompt_type = data.get("promptType", "resume")
    user_data = data.get("userData", {})

    # The log from the original code remains helpful for debugging
    print("---- USER DATA RECEIVED ----")
    print(json.dumps(user_data, indent=2))
    print("-----------------------------")

    try:
        # Build prompt from template + user data
        # NOTE: 'build_prompt' and 'generate_latex' are external functions
        prompt = build_prompt(prompt_type, user_data)
        latex_code = generate_latex(prompt)

        if not isinstance(latex_code, str):
            raise TypeError("generate_latex() must return a string")

        # Compile the LaTeX code into a PDF file
        # NOTE: 'compile_latex_to_pdf' is an external function
        pdf_path = compile_latex_to_pdf(latex_code, OUTPUT_DIR)

        # --- MODIFIED RETURN: Send the PDF file directly ---
        # This sends a response with Content-Type: application/pdf, which
        # the JavaScript client is designed to handle with res.blob().
        return send_file(
            pdf_path,
            mimetype='application/pdf',
            as_attachment=False,  # Display inline in the iframe
            download_name="generated.pdf"
        )
        # ----------------------------------------------------

    except Exception as e:
        # Standard error handling (returns JSON for JS client to parse)
        log = traceback.format_exc()
        print("----- BACKEND ERROR -----")
        print(log)
        print("--------------------------")

        return jsonify({
            "success": False,
            "error": str(e),
            "log": log
        }), 500


@app.route("/")
def index():
    # Serves the index.html from the configured FRONTEND_DIR
    return send_from_directory(FRONTEND_DIR, "index.html")

# The original /api/download route is now removed/redundant


if __name__ == "__main__":
    app.run(debug=True)
