#!/bin/bash

set -e 

INSTALL_DIR=${1:-"/opt/john"}
[[ $EUID -ne 0 ]] && INSTALL_DIR="$HOME/john"

echo "Installing John the Ripper to: $INSTALL_DIR"

if [ -f /etc/os-release ];then
  . /etc/os-release
  OS=$ID 
else
  echo "Unsupported OS"
  exit 1
fi 

install_deps(){
  echo "[+] Installing dependencies for $OS"

  case "$OS" in 
    ubuntu|debian)
      sudo apt update
      sudo apt install -y build-essential git libssl-dev libz-dev libbz2-dev libpcap-dev pkg-config yasm libgmp-dev libkrb5-dev libnss3-dev python3
      ;;
    arch)
      sudo pacman -Syu --noconfirm base-devel git openssl zlib bzip2 libpcap gmp krb5 nss python
      ;;
    fedora)
      sudo dnf install -y make git gcc openssl-devel zlib-devel bzip2-devel libpcap-devel gmp-devel krb5-devel nss-devel python3
      ;;
    *)
      echo "[-] Unsupported distro: $OS"
      exit 1
      ;;
  esac
}

build_john(){
  echo "[+] cloning John the ripper jumbo"

  mkdir -p "$INSTALL_DIR"
  git clone https://github.com/openwall/john.git "$INSTALL_DIR"|| (echo "[-] Clone failed" && exit 1)
  cd $INSTALL_DIR/src

  [ -d $INSTALL_DIR/src ] || { echo "[-] john/src does not exist"; exit 1; }
  echo "[+] configuring build...."
  ./configure --prefix="$INSTALL_DIR"

  echo "[+] Building with all cores"
  make -sj"$(nproc)" || { echo "[-] Build failed"; exit 1; }


  echo "[+] Installing to $INSTALL_DIR"
  make install

  echo "[+] Done"
}


 
add_to_path() {
  local profile="$HOME/.bashrc"
  local path_line="export PATH=\"\$PATH:$INSTALL_DIR/run\""
  local alias_line="alias john=\"$INSTALL_DIR/run/john\""

  if ! grep -Fxq "$path_line" "$profile"; then
    echo "$path_line" >> "$profile"
  fi

  if ! grep -Fxq "$alias_line" "$profile"; then
    echo "$alias_line" >> "$profile"
  fi

  echo "[+] Added John the Ripper to PATH and alias in $profile."
  echo "Reloading your terminal or run: source $profile"
  source ~/.bashrc
}

install_deps
build_john
add_to_path

echo "[+] John the ripper installed and ready to go"
