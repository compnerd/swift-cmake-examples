
#if defined(__ELF__) || defined(__MACH__) || defined(__WASM__)
  #if defined(L_EXPORTS)
    #define CLIBRARY_ABI __attribute__((__visibility__("default")))
  #else
    #define CLIBRARY_ABI __attribute__((__visibility__("default")))
  #endif
#else // assume PE/COFF
  #if defined(L_EXPORTS)
    #define CLIBRARY_ABI __declspec(dllexport)
  #else
    #define CLIBRARY_ABI __declspec(dllimport)
  #endif
#endif

void CLIBRARY_ABI f(void) {
}

