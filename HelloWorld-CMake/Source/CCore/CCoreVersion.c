
#if defined(__ELF__) || defined(__MACH__) || defined(__WASM__)
  #if defined(CCore_EXPORTS)
    #define CCORE_ABI __attribute__((__visibility__("default")))
  #else
    #define CCORE_ABI __attribute__((__visibility__("default")))
  #endif
#else // assume PE/COFF
  #if defined(CCore_EXPORTS)
    #define CCORE_ABI __declspec(dllexport)
  #else
    #define CCORE_ABI __declspec(dllimport)
  #endif
#endif

int CCORE_ABI CGetVersionMajor(void) {
  return 1;
}

