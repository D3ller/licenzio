char *string_to_lower(const char *src, char *dest);

struct License *get_available_license(int *c);

const struct License *find_license(const struct License licenses[], size_t count, char* license_name);