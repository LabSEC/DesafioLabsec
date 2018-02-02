#ifndef SIXTHMILESTONE_H
#define SIXTHMILESTONE_H

#include <libcryptosec/Pkcs12.h>
#include <libcryptosec/Signer.h>

#include "utils/trace.h"


/**
 * @brief <b>Sixth Milestone - Digital Signature</b><p>
 *
 * Last milestone you ecnrypted and later decrypted some text using
 * your public and private keys. When using a public-key cryptosystem
 * you have the ability to encrypt and decrypt data using different keys.
 * Basically, if you choose one key to encrypt, the other one is the only
 * key capable of decrypting your data. This is how we sign data.<p>
 *
 * Signing documents is usually done by encrypting the hash output of a
 * document using your Private Key. If you keep this Private Key a secret
 * and protect it properly, other parties may use your public key to verify
 * if the document was indeed signed by you. In other words, if you are the
 * only person to have access to your private key, then you are the only
 * person capable of producing this signature.<p>
 *
 * To verify a signature, all there is to do is decrypt the document's signature
 * using the public key. Take the original document's hash output and
 * compare to the result you obtained by decrypting the signature. If they match,
 * you have a valid signature.<p>
 *
 * In this milestone, you will produce a signature of paths::plainText using
 * your PKCS12 file.<p>
 *
 * - Use <b>Signer</b> class to sign and very signatures;<br>
 *
 * @see libcryptosec/Signer
 *
 * <b>SELF EVALUATION</b> (Requires previous milstones to run)<br>
 * In evaluation folder run '$make sixth'.<br>
 * You need to implement the evaluation for this milestone.<p>
 *
 * @author Lucas Perin
 */
class SixthMilestone {

 public:
    SixthMilestone();

    virtual ~SixthMilestone();


	/**
     * TODO Implement this function in the cpp file.
     */
    ByteArray sign(ByteArray& data, Pkcs12& userP12);

	/**
     * TODO Implement this function in the cpp file.
     */
    bool verifySignature(ByteArray& data, ByteArray& signature, Pkcs12& userP12);
};

#endif /*SIXTHMILESTONE_H*/
