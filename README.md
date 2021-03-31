# Out of source Dobby Plugins
Testing building Dobby plugins out of the main repo

## Usage
Build and install Dobby, setting the `-DEXTERNAL_PLUGIN_SCHEMA` CMake option to point to the `schema.json` file in this repo. This schema file will be merged with the schema defining the default plugins available within Dobby.

Then build and install the plugins in this repo
```
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
sudo make install
```

If you want to change the plugin schema, rebuild Dobby to update the libocispec headers and library.