# Ollama with a custom backend

This is a for of ollama where i try weird things with the backend.
Please do not use this for anything serious.

refer to the [original ollama](https://github.com/ollama/ollama) for a stable version.

## Goals of this fork

* A custom llama cpp server which is written in GO and only proxy code.
* The use of wasm plugins as samplers and grammar providers.
* Refactoring of the api to set things like: Gpu layers, model not by request, but by server instance.
* Statically linking the backend server and optimizations for my system :)
* Continues batching / batching support

## Changes

* Removed windows and mac support
* removed frontend
* Add dev environment (Devcontainer and vscode settings)
* Add dummy backend which is statically linked with ollama
