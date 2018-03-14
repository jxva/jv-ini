# Parse .ini configuration file using ANSI C

If you just need to parse the .properties configuration file, you can also use https://github.com/jxva/jv-properties

## Features

- No dynamic memory allocation
- No dependence
- ~100 LOC
- Supports for separating key and value using '=' or ':'
- Supports comments using '#' or ';'
- Supports value is a string
- Uses callbacks

## Getting Started

### test.ini

```ini
hello=world
ni = hao

project = ini
version = 0.1.0
test    =   no

[section1]

key1 = hello
key2= 2.56
key3:12

;; this is a comment
test1 : somethine else here

url = http://129fdsa.com:8080/fdsa?fdas=fdasf&fdsa=vcsa&reqwrw#fdsa

;ffffffffffffffffff

; this is also a comment
# and yet another comment
[section 2]

key1 = "something       in section   2"
test1: true


#ignore
[config]
    name = "Michael Lazear"
date = 12/9/1873
#[data]
    town = Margaritaville
age    = NaN
[output]
format=utf-8
language=english
long="This string
spans multiple
lines"

dsfsa=fdsafsa
```

### jv_ini_main.c

```c
#include <jv_ini.h>

static jv_int_t callback(jv_string_t *section, jv_string_t *key, jv_string_t *value);

static jv_int_t callback(jv_string_t *section, jv_string_t *key, jv_string_t *value) {
  printf("[%s:%lu][%s:%lu] = [%s:%lu]\n", section->data, (jv_uint_t)section->len, key->data, (jv_uint_t)key->len, value->data, (jv_uint_t)value->len);
  return JV_OK;
}

int main(int argc, char *argv[]) {
  FILE *fp;
  char *file = "test.ini";

  fp = fopen(file, "r");
  if (!fp) {
    fprintf(stderr, "Error opening %s\n", file);
    return JV_ERROR;
  }

  jv_ini_load(fp, callback);

  fclose(fp);
  return 0;
}
```

## Build

    $ make

## Run

    $ ./jv_ini_main

## Out Print

```ini
[(null):0][hello:5] = [world:5]
[(null):0][ni:2] = [hao:3]
[(null):0][project:7] = [ini:3]
[(null):0][version:7] = [0.1.0:5]
[(null):0][test:4] = [no:2]
[section1:8][key1:4] = [hello:5]
[section1:8][key2:4] = [2.56:4]
[section1:8][key3:4] = [12:2]
[section1:8][test1:5] = [somethineelsehere:17]
[section1:8][url:3] = [http://129fdsa.com:8080/fdsa?fdas=fdasf&fdsa=vcsa&reqwrw#fdsa:61]
[section2:8][key1:4] = ["something       in section   2":32]
[section2:8][test1:5] = [true:4]
[config:6][name:4] = ["Michael Lazear":16]
[config:6][date:4] = [12/9/1873:9]
[config:6][town:4] = [Margaritaville:14]
[config:6][age:3] = [NaN:3]
[output:6][format:6] = [utf-8:5]
[output:6][language:8] = [english:7]
[output:6][long:4] = ["This string
spans multiple
lines":34]
[output:6][dsfsa:5] = [fdsafsa:7]
```

## License

This project is under MIT License. See the [LICENSE](LICENSE) file for the full license text.

