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
