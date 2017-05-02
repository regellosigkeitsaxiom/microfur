with import <nixpkgs> {};
#{ pkgs ? import <nixpkgs>, ... }:

#let
#f = { stdenv, pkgs }: stdenv.mkDerivation rec {
stdenv.mkDerivation rec {
  src = ./.;
  version = "1.0.0.0";
  name = "microfur-${version}";
  buildInputs = with pkgs; [ stlink gcc-arm-embedded bash ];
  buildPhase = ''
  '';
  installPhase = ''
    mkdir -p $out/bin
    cp microfur $out/bin/microfur
    chmod +x $out/bin/*
    cp -r templates $out/templates
    cp -r Cube $out/Cube
  '';
}

#in
#pkgs.callPackage f {}
