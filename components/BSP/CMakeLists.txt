set(src_dirs
            LED
            HW
            KEY
            EXIT 
            )

set(include_dirs
            LED
            HW
            KEY
            EXIT
            )

set(requires
            driver
            nvs_flash
            esp_psram
            button
            )

idf_component_register(SRC_DIRS ${src_dirs} INCLUDE_DIRS ${include_dirs} REQUIRES ${requires})

component_compile_options(-ffast-math -O3 -Wno-error=format=-Wno-format)
