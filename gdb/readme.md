## notes

download the arm-none-eabi-gcc from https://launchpad.net/gcc-arm-embedded
and build the arm-none-eabi-gdb yourself, as the downloaded one doesn't support python
and has not `target sim`.

```
./configure \
    --target=arm-none-eabi \
    --prefix=/usr/local \
    --enable-languages=c,c++ \
    --with-python=/usr/bin/python

make -j4
make DESTDIR=/tmp/armgdb install
```

before starting gdb, use `openocd -f /usr/local/share/openocd/scripts/board/st_nucleo_f4.cfg`.
openocd listen on :3333 as gdbserver, :4444 for telnet cli.

then start the gdb by `arm-none-eabi-gdb -x .gdb.arm.init`
