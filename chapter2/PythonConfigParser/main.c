#include <Python.h>
#include "PythonConfigParser.h"

static
void print_config(const char * config_file)
{
    struct ConfigSections sections;
    ParseSectionsFromConfig(config_file, &sections);

    size_t i;
    for (i = 0; i < sections.number_of_sections; ++i) {
        const char *current_section = sections.sections[i];
        printf("[%s]\n", current_section);

        struct ConfigSectionKeys sectionKeys;
        ParseKeysFromSectionFromConfig(config_file, current_section, &sectionKeys);

        size_t j;
        for (j = 0; j < sectionKeys.number_of_keys; ++j) {
            const char * current_key = sectionKeys.keys[j];            
            char *key_value = ParseConfigKeyFromSection(config_file, current_section, current_key);

            printf("%s = %s\n", current_key, key_value);
        }
        free(sectionKeys.keys);
    }
    free(sections.sections);
}

int main(int argc, char ** argv)
{
    // requires config file argument
    if (argc < 2) {
        printf("Please pass a sample config file as part of the command line arguments.\n");
        return -1;
    }
    
    // Init Python Runtime
    Py_Initialize();

    // Init PythonConfigParser
    initPythonConfigParser();

    // Print out all sections and values from config
    print_config(argv[1]);
    
    // Close Python Runtime
    Py_Finalize();
    return 0;
}
