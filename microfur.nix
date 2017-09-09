with import <nixpkgs> {};
#{ pkgs ? import <nixpkgs>, ... }:

#let
#f = { stdenv, pkgs }: stdenv.mkDerivation rec {
stdenv.mkDerivation rec {
  src = fetchFromGitHub {
    owner = "regellosigkeitsaxiom";
    repo = "microfur";
    rev = "3b54837e0e710e5a8e56a3f04cd63f85765952de";
    sha256 = "04jv2sszpkajr473qfi800k34irdc9ssqg9i6vb8ikzlzl183996";
  };
  version = "1.0.0.0";
  name = "microfur-${version}";
  buildInputs = with pkgs; [ openssh stlink gcc-arm-embedded bash ];
  buildPhase = ''
  '';
  installPhase = ''
    mkdir -p $out/bin
    mkdir -p $out/etc/microfur/
    cp microfur $out/bin/microfur
    chmod +x $out/bin/*
    cp -r Documentation templates Drivers $out/etc/microfur/
  '';
}

#in
#pkgs.callPackage f {}
