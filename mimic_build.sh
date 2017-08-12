#!/bin/sh

SOURCE_DIR="$PWD/"
BUILD_DIR="$PWD/build/"
INSTALL_DIR="$PWD/install/"

build_component() {
  COMPONENT="$1"
  shift
  echo "${COMPONENT}"
  if [ ! -e "${BUILD_DIR}/${COMPONENT}/meson-private/coredata.dat" ]; then
    echo "Running meson at ${BUILD_DIR}/${COMPONENT}"
    mkdir -p "${BUILD_DIR}/${COMPONENT}" && \
    meson "${BUILD_DIR}/${COMPONENT}" "${SOURCE_DIR}/${COMPONENT}" --prefix="${INSTALL_DIR}" "$@" || exit 1
  fi
  ninja -C "${BUILD_DIR}/${COMPONENT}" test install || exit 1
}

build_component_autotools() {
  COMPONENT="$1"
  shift
  echo "${COMPONENT}"
  (cd "${SOURCE_DIR}/${COMPONENT}" && ./autogen.sh) || exit 1
  mkdir -p "${BUILD_DIR}/${COMPONENT}_autotools" || exit 1
  (cd "${BUILD_DIR}/${COMPONENT}_autotools" && \
   "${SOURCE_DIR}/${COMPONENT}/configure" --prefix="${INSTALL_DIR}" && \
   make && make install || exit 1)
}


# Set pkg-config path:
which dpkg-architecture >/dev/null 2>&1 && export PKG_CONFIG_PATH="${PKG_CONFIG_PATH}:${INSTALL_DIR}/lib/"`dpkg-architecture -qDEB_HOST_MULTIARCH`"/pkgconfig"
export PKG_CONFIG_PATH="${PKG_CONFIG_PATH}:${INSTALL_DIR}/lib/pkgconfig"

# Set LD_LIBRARY_PATH for tests:
which dpkg-architecture >/dev/null 2>&1 && export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${INSTALL_DIR}/lib/"`dpkg-architecture -qDEB_HOST_MULTIARCH`
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${INSTALL_DIR}/lib"


# Build mimic components:
build_component "mimic-core"
build_component "mimic-english"
build_component "mimic-cmu_us_slt"
#build_component_autotools "mimic-vid_gb_ap"
#build_component "mimic-vid_gb_ap"
build_component "mimic-full"

