# Licenzio

A CLI tool for adding license files to projects.

## Usage

```bash
licenzio mit # Create the license MIT
licenzio apache # Create the license Apache
licenzio apache -o /Users/corentin # Create the license Apache in /Users/corentin
licenzio -l # List the available licenses
```

## Todo 

- [x] Create the file when the license is selected.
- [ ] Add the possibility to replace mustache tag by whathever you want.
- [ ] Choose the output for the file.

## Build 

using `make`
```bash
make;
```

execute
```bash
./licenzio -h
```

> [!WARNING] 
This CLI overwrites your existing `LICENSE` file.

Reproduction in C of the project from @khalidbelk