#!/usr/bin/env bash

set -e
cd "$(dirname "$0")/.."

CLI_NAME=licenzio
BIN_DIR="$HOME/.local/bin"

make -s

mkdir -p "$BIN_DIR";
install -m 755 "$CLI_NAME" "$BIN_DIR/$CLI_NAME"

if command -v "$CLI_NAME" > /dev/null; then
    echo "$CLI_NAME successfully installed. Try \"$CLI_NAME -h\""
else
    echo "$CLI_NAME installed to $BIN_DIR, but not in your PATH" >&2
    exit 1
fi
