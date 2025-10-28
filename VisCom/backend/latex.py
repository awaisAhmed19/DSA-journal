
# backend/latex_compiler.py
import os
import subprocess
import tempfile
import uuid


def compile_latex_to_pdf(latex_code: str, output_dir: str) -> str:
    """
    Writes LaTeX code -> .tex -> compiles -> returns .pdf path
    """
    os.makedirs(output_dir, exist_ok=True)

    session_id = str(uuid.uuid4())[:8]
    tex_path = os.path.join(output_dir, f"resume_{session_id}.tex")
    pdf_path = os.path.join(output_dir, f"resume_{session_id}.pdf")

    # Write LaTeX source
    with open(tex_path, "w") as tex_file:
        tex_file.write(latex_code)

    # Compile LaTeX -> PDF (quiet mode)
    compile_cmd = [
        "pdflatex",
        "-interaction=nonstopmode",
        "-halt-on-error",
        f"-output-directory={output_dir}",
        tex_path,
    ]

    try:
        subprocess.run(compile_cmd, check=True,
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    except subprocess.CalledProcessError as e:
        raise RuntimeError(f"LaTeX compilation failed: {e.stderr.decode()}")

    # Cleanup .aux, .log files
    for ext in [".aux", ".log"]:
        f = os.path.join(output_dir, f"resume_{session_id}{ext}")
        if os.path.exists(f):
            os.remove(f)

    if not os.path.exists(pdf_path):
        raise FileNotFoundError(
            "PDF not generated. Compilation failed silently.")

    return pdf_path
