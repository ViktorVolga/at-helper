DESCRIPTION = "Simple app for working with modem on serial port"
LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "git://github.com/ViktorVolga/at-helper.git;protocol=https;branch=main"
SRCREV = "caa0ab488d0f6d52fcdadef8706de5c470a5aaf4"

S = "${WORKDIR}/git"

inherit cmake

#EXTRA_OECMAKE = ""

