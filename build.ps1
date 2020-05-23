$cwd = Get-Location
docker run -it --rm --env VCPKG_FORCE_SYSTEM_BINARIES=1 -v ${cwd}:/tmp/build gazzyt/alpine-build-vcpkg:1.0 ash -c 'cd /tmp/build/build; cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET="x64-linux-static" .. ; make'
