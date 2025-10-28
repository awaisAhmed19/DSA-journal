#!/usr/bin/env bash
set -e

echo "Building VisCom environment..."
echo "--------------------------------"

# --- Define Dependency Lists ---
PYTHON_DEPS="python3 python3-pip"
MACOS_TEX_DEPS="mactex" # MacTeX is typically installed via a download or Homebrew cask
TEX_BASE_DEPS="texlive-base texlive-latex-base"
TEX_EXTRA_DEPS="texlive-latex-extra texlive-fonts-recommended texlive-fonts-extra"

# ---- Detect and Install System Dependencies ----

if command -v brew >/dev/null 2>&1; then
  # Detected macOS with Homebrew
  echo "Detected macOS (Homebrew)"

  # Python is usually pre-installed, but we ensure pip and venv module are available.
  # Python 3 is typically installed as 'python3' via Homebrew.
  brew install python

  # TexLive/MacTeX installation on Mac is large and often done via cask.
  if ! command -v pdflatex >/dev/null 2>&1; then
    echo "Installing MacTeX (TexLive for macOS). This may take a while..."
    brew install --cask mactex
  else
    echo "TexLive (MacTeX) is already installed."
  fi

elif [ -f /etc/arch-release ]; then
  # Detected Arch Linux
  echo "Detected Arch Linux"

  echo "Installing system packages (Python and TexLive)..."
  sudo pacman -Syu --noconfirm python python-pip texlive-core texlive-latexextra texlive-fontsextra

elif [ -f /etc/debian_version ]; then
  # Detected Debian/Ubuntu
  echo "Detected Debian/Ubuntu"

  echo "Updating package list..."
  sudo apt update

  echo "Installing system packages (Python and TexLive)..."
  sudo apt install -y ${PYTHON_DEPS} ${TEX_BASE_DEPS} ${TEX_EXTRA_DEPS}

elif [ -f /etc/redhat-release ] || [ -f /etc/fedora-release ]; then
  # Detected Fedora/RHEL/CentOS
  echo "Detected Fedora/RHEL/CentOS"

  echo "Installing system packages (Python and TexLive)..."
  # Fedora/RHEL often use 'python3' and 'dnf' or 'yum'
  sudo dnf install -y python3 python3-pip texlive-scheme-basic texlive-latex texlive-collection-fontsrecommended

else
  echo "--------------------------------"
  echo "Error: Unsupported OS detected."
  echo "Please install Python 3, pip, and a full TeX Live distribution manually."
  exit 1
fi

echo "--------------------------------"

# ---- Python Virtual Environment Setup ----

if [ ! -d "venv" ]; then
  echo "Creating Python virtual environment..."
  # Ensure we use python3 command for venv creation
  python3 -m venv venv
else
  echo "Virtual environment 'venv' already exists."
fi

# Activate the environment
echo "Activating virtual environment..."
source venv/bin/activate

# ---- Python Dependencies Installation ----
echo "Installing Python dependencies from requirements.txt..."

# Upgrade pip for stability
pip install --upgrade pip

# Install project dependencies
pip install -r requirements.txt

# ---- Done ----
echo "--------------------------------"
echo "Build complete. Your environment is ready."
echo "To run the server, execute the following commands:"
echo ""
echo "source venv/bin/activate"
echo "python backend/app.py"
echo "--------------------------------"
