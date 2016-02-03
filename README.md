# MiniTools

A repository containing small but handy tools for unix.

## fltr

`fltr` is a tiny, lightning fast, fuzzy text filter. For now it simply matches
from left to right, without sorting the output or even making sure that the
most relevant part of the string is matched. Matching characters are
highlighted in red.

### Usage

```bash
command | fltr needle
```

### Installation

```bash
$ make
$ make install
```

## stack

Under development
