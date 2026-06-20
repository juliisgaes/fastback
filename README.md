# Fastback.
## un videojuego simple en desarrollo.
### instrucciones para compilar:
```
# clonar el repositorio.
git clone --depth 1 https://github.com/juliisgaes/fastback.git .

# entrar en el directorio del repositorio.
cd fastback/

# compilar para linux.
gcc -I raylib/raylib-6.0_linux_amd64/include/ /usr/lib/libX11.so.6.4.0 /usr/lib/libm.so.6 fastback.c raylib/raylib-6.0_linux_amd64/lib/libraylib.a -O3 -o fastback

# compilar para windows en linux.
x86_64-w64-mingw32-gcc -I raylib/raylib-6.0_win64_mingw-w64/include/ fastback.c raylib/raylib-6.0_win64_mingw-w64/lib/libraylib.a -lgdi32 -lwinmm -O3 -o fastback.exe -Wl,--defsym=stat64i32=_stat64i32
```
