cmd_Makefile := cd ..; /usr/local/lib/node_modules/node-gyp/gyp/gyp_main.py -fmake --ignore-environment "--toplevel-dir=." -I/home/angus/Desktop/nodeV4/prjAddons/addonSrc/build/config.gypi -I/usr/local/lib/node_modules/node-gyp/addon.gypi -I/home/angus/.node-gyp/4.6.1/include/node/common.gypi "--depth=." "-Goutput_dir=." "--generator-output=build" "-Dlibrary=shared_library" "-Dvisibility=default" "-Dnode_root_dir=/home/angus/.node-gyp/4.6.1" "-Dnode_gyp_dir=/usr/local/lib/node_modules/node-gyp" "-Dnode_lib_file=/home/angus/.node-gyp/4.6.1/<(target_arch)/node.lib" "-Dmodule_root_dir=/home/angus/Desktop/nodeV4/prjAddons/addonSrc" "-Dnode_engine=v8" binding.gyp