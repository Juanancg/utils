/*typedef CPluginInfoList (*GetPluginInfoList)(void);

#if _WINDLL
HINSTANCE hGetProcIDDLL = LoadLibraryA(sDllPath.c_str());

#else
void* hGetProcIDDLL = dlopen(sDllPath.c_str(), RTLD_LAZY);

#endif

#if _WINDLL
GetPluginInfoList GetInfoList = (GetPluginInfoList)GetProcAddress(hGetProcIDDLL, "GetPluginInfoList");
#else
GetPluginInfoList GetInfoList = (GetPluginInfoList)dlsym(hGetProcIDDLL, "GetPluginInfoList");
#endif

GetInfoList();  // Function Call
*/

#include <dlfcn.h>

#include <iostream>

int main() {
    using std::cerr;
    using std::cout;

    cout << "C++ dlopen demo\n\n";

    // open the library
    cout << "Opening hello.so...\n";
    void* handle = dlopen("./hello.so", RTLD_LAZY);

    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }

    // load the symbol
    cout << "Loading symbol hello...\n";
    typedef void (*hello_t)();

    // reset errors
    dlerror();
    hello_t hello = (hello_t)dlsym(handle, "hello");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'hello': " << dlsym_error << '\n';
        dlclose(handle);
        return 1;
    }

    // use it to do the calculation
    cout << "Calling hello...\n";
    hello();

    // close the library
    cout << "Closing library...\n";
    dlclose(handle);
}