#!/usr/bin/env bash

nix-shell -p python27Packages.pyserial --run 'make upload'
