
import os
import subprocess
import tempfile
import shutil


def compile_latex_to_pdf(latex_code: str, output_dir: str) -> str:
    """
    Compiles LaTeX source (string) into a PDF file and returns the final path.
    Requires `pdflatex` to be installed.
    """
    # Ensure pdflatex exists
    if shutil.which("pdflatex") is None:
        raise FileNotFoundError("pdflatex not found. Please install TeX Live.")

    os.makedirs(output_dir, exist_ok=True)

    with tempfile.TemporaryDirectory() as temp_dir:
        tex_path = os.path.join(temp_dir, "document.tex")
        pdf_path = os.path.join(temp_dir, "document.pdf")
        final_pdf_path = os.path.join(output_dir, "generated.pdf")

        # Write LaTeX content to temp file
        with open(tex_path, "w", encoding="utf-8") as f:
            f.write(latex_code)

        # Compile LaTeX → PDF
        result = subprocess.run(
            ["pdflatex", "-interaction=nonstopmode", tex_path],
            cwd=temp_dir,  # FIX: compile inside temp_dir
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        # print("---- PDFLATEX STDOUT ----")
        # print(result.stdout)
        # print("---- PDFLATEX STDERR ----")
        # print(result.stderr)

        # Check if compilation succeeded
        if not os.path.exists(pdf_path):
            raise RuntimeError(
                "PDF compilation failed. Check LaTeX output for errors.")

        # Move the PDF to output folder safely
        shutil.copy2(pdf_path, final_pdf_path)

        return final_pdf_path
