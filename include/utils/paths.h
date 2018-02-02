#ifndef PATHS_H
#define PATHS_H

namespace paths {

    /**
    * PlainText path
    */
    extern const char* plainText;

    /**
    * Key file paths
    */
    extern const char* userKeyPairPath;
    extern const char* rootCaKeyPairPath;

    /**
    * Certificate file paths
    */
    extern const char* userCertificatePath;
    extern const char* rootCaCertificatePath;

    /**
    * PKCS12 File paths
    */
    extern const char* userP12Path;
    extern const char* rootCaP12Path;

    /**
     * Signed file paths
     */
    extern const char* userSignedDataPath;
};
#endif /*PATHS_H*/
