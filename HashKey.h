#ifndef HASHKEY_H_INCLUDED
#define HASHKEY_H_INCLUDED
#include "Board.h"

/* Hash Keys , Generated with rand() and saved to save computations and ensuring the hashing is the same for every platform. */

const U64 PieceKeys[12][64] = { 0x1cf0862fa4118029 , 0xd2a5cab966b3d6c , 0x983776bc76f89649 , 0xc25b6ba985d981eb , 0x401323cf9c867e87 , 0x79a0d2472206b05e , 0xd5a24e6cea6f1547 , 0x685179aef221cdc8 , 0x9ecfbe96ae81f01f , 0x4dcba787dd929238 , 0x5ffebfe5b5fe63cb , 0xad7129835109b23b ,
                                0xe655ab85edb01c , 0x896808bb91a8759a , 0x23492f84ae7eeb36 , 0xcbe93e5f5d4f3bf6 , 0x49be578518a7ccad , 0x46cd673409b32e40 , 0x1587780cbf5bc230 , 0xdb3222089f7b5422 , 0xe7b4487fcc592e1 , 0x2f7722409b4ca6ca , 0xe9501a4b3824939d , 0x27d2f35744c96c5 ,
                                0x391988f259f55db2 , 0x41f7ef35ae33e0bf , 0xea9b908b423f6ad6 , 0x98cafd7bfcc18d66 , 0x1511fb1a57ffbc61 , 0xcbd3a987bee8a2cd , 0xd65cdadcb0b91916 , 0x79295fd3c1c271f0 , 0xca073afa0c6bc402 , 0xe1c243f275e59953 , 0x45618927bc3a2833 , 0x499a96a7f56a5dd5 ,
                                0x20f9e00d493f2059 , 0x38d9e3b30d7a6d22 , 0xfafa78121d168e90 , 0xab23a6765bf30975 , 0x8885727dcee037e5 , 0xfb21ded120439481 , 0xdfec25b515801850 , 0x7182b401463dffbe , 0x84a3fca08319f73b , 0x4a0c86769a496270 , 0x9a27d3215dd8b9ce , 0x490d5711a7fc6a15 ,
                                0x6e7b31c3af399796 , 0x795a965a26b3982f , 0x89caf7b405253f4a , 0x193764c5b37d5876 , 0x90b11749275774ad , 0x34e4b236d4297cfe , 0x3be8bb3d379e0de5 , 0x5a416273851429d8 , 0x74c7ad165cb045c5 , 0xdbceca5649c54027 , 0x8b99bbf27d6169d0 , 0x5c8f221a8824f8d4 ,
                                0x1e0282503d30ce08 , 0x83a2302946b5293b , 0xb1d53535a34675c1 , 0x1825f9631fcbb087 , 0x1652b366a20ed815 , 0x9dcfd3f00670da9b , 0x2c90cc29dfcd5fa8 , 0x72d3542ffd2a2db5 , 0x9cabe746f9190d9 , 0xc21b347443942a38 , 0x1da9d717a6336ea1 , 0x137b33bfad4e1030 ,
                                0xc51c4ae967f1159f , 0x886cb9d1f35a549b , 0x2a1524a279a3662a , 0x210f1b5d88bd2079 , 0xa39bf1899358c963 , 0x48c444fb3b68e29 , 0x99d7f7cd32897296 , 0x13abdba24e9feda6 , 0x814d81b8ff07456d , 0xbe43a848060f36a1 , 0x71483dcfc80192c2 , 0x5660bd4515878784 ,
                                0x5d7931187594791b , 0x6868c023909632e7 , 0xd41512bccf6e3308 , 0x101d7c7c9bdf78fe , 0x5247727432504cff , 0x8150ed5f80463106 , 0x2a97d9f40426ed73 , 0x1248d5f0a1ede6be , 0xfde600feb1c65d2b , 0x6f2a91a9c5785a70 , 0x89eb7f6a894aa332 , 0x537f96399785f613 ,
                                0x91b3fcdf615f1eca , 0x82bfb906c520b88a , 0xb74e46bdb7b4634f , 0xd4fa6cf3474ce014 , 0x63f6860e902204f0 , 0xb3217e0cf8a9cf66 , 0xc7499d17aa0852a1 , 0x591cd45cc9a65503 , 0xd8955283a298f8b4 , 0x7cb9412c166ab2cf , 0xd12292e758ec08ff , 0x29ab2e89e93c93f4 ,
                                0xdd5f0cb06bce387c , 0x46447c083cc3998c , 0xc712b261f95317b8 , 0xd429c923432d5ab0 , 0xe56374f6d73f299 , 0x8635a9e039d8b2de , 0x5bc837d9eef4ad41 , 0xfae308b90ccf91d5 , 0xee84c38021212f15 , 0x3b008e0869e8c24c , 0x35ae60e3c4d98a2f , 0xe115eca28921d940 ,
                                0x39d9f6354cb7dcca , 0xe0cb5173864ac5a1 , 0x787ed74abe13bb65 , 0x60ccac6f97d0d8ad , 0x2c8d29f003e495b4 , 0x1709a04b1f04a934 , 0xb598ccd5b08bcd8f , 0xb0db1fe9a7e4789d , 0xb48c29ce18c0ee88 , 0x407f209899094e68 , 0x8ba2ecdc7bf3edd0 , 0xd98532a4b806e778 ,
                                0xb96e52e65d94e586 , 0x7029eafeab0e6874 , 0x75f2b8ac0edaabb8 , 0xde4d94202e6f8ef5 , 0x3f7178f679ba448d , 0x6d94be823308f365 , 0x543d73bdcbded079 , 0xfb6c057872705db8 , 0xb1fe9b5ef39e0a6e , 0x7311f8629e454962 , 0xab10f4b940fbff5c , 0xd6c35a6d199093b ,
                                0x7a362770f1e32f84 , 0x505dc9043e251a30 , 0xa593c04bc301936f , 0x81736d541a882bef , 0xae05150a55a1d981 , 0x1428eee78374c8f6 , 0xd90d82cc5f246e81 , 0x34b03b37b74f63a4 , 0xac3ffa842fcc528c , 0x770af0b3fa66f443 , 0xc2b7adaff4acad50 , 0xd16fe20a3181d427 ,
                                0x424924ee73afd789 , 0xea5cbf4f01302c4e , 0xd0564dd0a8cc7502 , 0xb05d990529db322b , 0x1fbc519ce89791b8 , 0x457b1907533e9b7e , 0xc17df80468fcdd3 , 0x1c687ff5ad8b3a6b , 0x84a316057c8ccf83 , 0x93f176cba316252b , 0xac3e156f3cee3f0e , 0x1fd297db731eb90e ,
                                0x5eb1b2ebfa3a5092 , 0xaf0bdc755cc83ea4 , 0x2f0ed7600cfe2040 , 0x18e6c11ae90b854b , 0xa20b5fdf43edb921 , 0x1551b5208b0f0672 , 0x938bcdae1a4653a8 , 0xcd7f03e9fd7954e , 0x520eac0755ba0094 , 0xaa68d49639085ddc , 0xf7741ea06f2dddf2 , 0x9746da4779e58e5c ,
                                0x26aaa140b0ba6f49 , 0x91dee6c2ca8d08ac , 0x3b0b729027918f26 , 0x8cf1098d6adcf533 , 0x22baa68ab170ffad , 0xaf5ca642a52e9732 , 0xb32ba3ddd374b0dc , 0xc0075c3170b4e2b5 , 0xb7eaeec3734c3693 , 0x8ec082f7e3cd1e87 , 0x4a1ccfb543d16db2 , 0xdcabfd1dd05e60c6 ,
                                0x1ca550b58347c6c3 , 0x1ea091b52ed48314 , 0xb7b5cca3538c6601 , 0xc195898000e5373 , 0x5085f57583ae93cf , 0x9fb50df5f314d953 , 0xd144dbfa9e86a5cc , 0x94f09d6009271255 , 0xd3d71a0dc2fc682b , 0xe3ab86a8113d20d5 , 0xc9bf9b0878cfeffa , 0x7302b638bc29636 ,
                                0x4e96317ba7dff27d , 0xbde0ff04bff4dd85 , 0x32bc491997f612c6 , 0x6a5200fd2ddcdef3 , 0x2b8083fd345cde32 , 0x1083dc783a96532d , 0xb6b20750c07c3974 , 0x8c1247c5a01bf5a2 , 0xe3a6f8ad420e1b53 , 0x289f6a9cb6876737 , 0xed012749a9666f46 , 0x565db1f6023d2ef6 ,
                                0x2f0ae672b9892997 , 0xf38dce4239366cb6 , 0xb0438d8ea7f047b0 , 0xdae80957d11d11df , 0x6c3793926dcfaba , 0x5052508748b0dea6 , 0xa7657cde155e5fc8 , 0xaaeb20c628618677 , 0x4d284882ad35400e , 0x375c7b03d0df4c71 , 0x2a060f3fc0edad01 , 0x298ca93e01c4b11a ,
                                0xa887ac417b9e3751 , 0xeb31adff775f7cb3 , 0x909fd1e85fe84d19 , 0xdf6cfb813bfd1dd4 , 0x14e28d0644e4cabf , 0x8c8109bcb7fc0a3f , 0xc8f8a8f00dd6cb51 , 0x4ddd9744934a2002 , 0xf9307c7d9c981869 , 0xd41c73d043caff63 , 0xff5b4fd60ed08edd , 0xa83fa8f3959c0a31 ,
                                0x54acb33bfb2e34c5 , 0xfd5bd18c3ce23369 , 0x6516dbd7a5f1669c , 0xf20ad7003c5f224b , 0x60aa80da8b423c87 , 0x5367807688b66e5f , 0x54c7b51271e5e60a , 0x27fae7c3b5e575f3 , 0x4b71eb6601fa09b1 , 0xfbeb05d3d3111718 , 0x4ce84b7be1a38774 , 0x62e720ef886ff32e ,
                                0xb8a38b19e4861fe6 , 0xd1aefe3fbbae6f74 , 0x71291ca4f337476b , 0x8ac0518f98d9e944 , 0x2ba61f6dbcc3a404 , 0x199ba655887222dd , 0xcb118f4f4eb72d7b , 0xf8378799fee255e7 , 0xf8998a725efff2f2 , 0x14a4856a56482b13 , 0x5a6839d2ef56f61e , 0x5b8c420ff1142292 ,
                                0x90552f7f42d72bb8 , 0x91953546298cf2b , 0x9de358516c9751ec , 0x570380afb2553635 , 0x33eae22f513bc0ce , 0xe5e14245e764c0d3 , 0x64a1e7bd95996e16 , 0x4385a2348b09ff10 , 0x843442ada99364b7 , 0xfa1dc5b464011bd8 , 0x90eb2aaeb090ba13 , 0x5de55229b7e358de ,
                                0x19e6d451fffa65cf , 0xa3b45f52cc6ecbeb , 0xcb80d0490541e99 , 0x734dd7481848f334 , 0xeab08b8f56a7cd62 , 0x2f418b1a79541ca0 , 0xf8830b5fd21219d0 , 0x1b59636a46601c28 , 0x47dc802f746cd5ff , 0x9bf35362d299f7b8 , 0x14e0d363b52074c3 , 0x650760ca2ba1337 ,
                                0x3affa0e0da578d0c , 0x3dcb860c4ea215a2 , 0x1f6121cc1eed0618 , 0xe0ef25d7d9a4861 , 0xbd2c75129a76b39a , 0x90ca93b84024a43d , 0xa336d353bd163602 , 0x9013f9de67e12b97 , 0xfd300a2311b8327c , 0xf7815211cca6a7e0 , 0xb6286d6697953774 , 0xbf376c9695987059 ,
                                0xa156b8db26ee3594 , 0x778c8a2705971a9d , 0xe24913aa0513aa98 , 0xd3891fd21c19e998 , 0x1938403c50ef426e , 0x7e76abd27e070dc3 , 0xb4f84f4f935e1c80 , 0x16d6ec73b5dce1e2 , 0x9c0c829d85d9de11 , 0x8182af33570451a3 , 0x83ab5d3a55f5981c , 0xc45b45d555db93bf ,
                                0x9807c21815751613 , 0xf2de5d371c92e795 , 0x3efca7f4acc03c6d , 0x4a141a3a74a2a657 , 0x2f3f4943d0b380ec , 0x1ebc8832ad47c23b , 0x2485a27474dc8bf9 , 0xb2406dcf20f75256 , 0xe6963d45c055098d , 0x2ad8cd8a46829805 , 0xa7fde8b03594697f , 0xb387f13a7e211312 ,
                                0x7331462c4ca79a31 , 0xfae0896baf484bf7 , 0xf424db04bb6b75ed , 0x1e48a4bf39d707ec , 0xaaf3ea9b586bfa74 , 0xd44615969bbab0a7 , 0xbbf0f9697354c390 , 0xe58e08ebe3c769f4 , 0xa484abcab0d374a3 , 0x3fb3c360335a98b , 0x2c89d375b804128b , 0xba2eedddf0c0b9d1 ,
                                0x9b59bed254a69654 , 0xf093b7c843076e72 , 0x48873234e35f0a8b , 0xd6948210137e89e1 , 0x444cb047f4852037 , 0x7b4fa91a07caf550 , 0x4cfa50cd960ea5ba , 0x91a891bdb511889e , 0xd7388f2a6e47792c , 0xfa8e3c4c9760c640 , 0x88be48f4073240f2 , 0x976bf7d1b6eb2f41 ,
                                0xfa1ccc21257fb896 , 0xc027c5f1758bbdc5 , 0x26908830ce318533 , 0xfdb55168c88438ab , 0xd24aaa073b1f9bf0 , 0x6630b1313d278151 , 0xe27112f578af1e58 , 0x939774e33aab4481 , 0xb8190cc94636fb9f , 0xa4a3a8066806aa09 , 0xcacb0a805e98f307 , 0x51ef9d835a6aca97 ,
                                0x11a1e3920fd51308 , 0x1a746e851f6869c8 , 0x5e5fa940659d1e8 , 0x7b9c6ca17d95c290 , 0xd105fb48340eafe3 , 0xc8a1a34cf142e62 , 0x7c1d03f9cb2ec817 , 0x83dc316a0af123c4 , 0x8ab956596a1d1ccf , 0x5219e789516872c , 0xcf60a8d8979614dc , 0x953383167fd2162 ,
                                0xb05876da15a05b27 , 0x61837090816d0ba , 0xc07e2fd865e26e9b , 0x6c3a7252965fc6d8 , 0x248417f023010015 , 0xa89e497cae52eae8 , 0x7ab0e31858eb8d07 , 0x7e3637a1eaedd870 , 0x1446239110f4c8e5 , 0x3cd1a6e09f39fd1d , 0x75fa9ff39ee32c9c , 0x6254326c28561c3d ,
                                0x6a7de18ea91bba9d , 0x63bfe66329a58ccc , 0x58c33c95f0437f4c , 0x2bb27709676bef36 , 0xf9d4ecf389c760cb , 0x3650e20a38b4ea3c , 0x9942b8609ce33e79 , 0xe14db7fdd70fcaa1 , 0xd1bb2cb182d8ff9f , 0x33998e7f1143378a , 0x27307c2079285224 , 0xc577b7a8fdb89db4 ,
                                0x9aeb7c9d67c5cd3b , 0xf91656e562068ded , 0x7e3bff111d574165 , 0xa775e88886a09f77 , 0x5ff863bb98b70648 , 0x2f4d75c48048053a , 0xc9cdd5b44907e01c , 0x2dc7fd09448d7ced , 0x5e60a4dee4cf71ca , 0xbd5954024b3b21a8 , 0x8a8fdf745cb4ede7 , 0xcf9617e6b4388774 ,
                                0x4ab26938787a835 , 0x7ddbc6e8cffc6bd6 , 0x763d781b3b701a55 , 0x6bc7be1d285dc76b , 0x1a0c3f5de33631c1 , 0xd7d79642e826370b , 0xb23c821606b42259 , 0x6441fb6aa9601713 , 0x24112345faaccffc , 0xb5f3a381ed1059be , 0x717dae8b4653fb02 , 0xfbce1a5f7297a9b9 ,
                                0xb6d5dfb50bfd869f , 0x2ea53af979a5dc57 , 0xf624b83f2e8f3d6a , 0x2d27e0ffd739a312 , 0x644062a38e5ab7a3 , 0xd7c2682694dfe235 , 0xaf795648164447ed , 0x69b4b2f4b8e322e7 , 0x76c65a14751ae694 , 0x67fd1609bee1d0f2 , 0x949f7b954f41c89c , 0xb660ea4b99c2e8f3 ,
                                0xac37e8e2f9d8f726 , 0xc0c4548efab079e3 , 0xb497a84232b7a4f2 , 0xb52787c9f461f50a , 0xcd167ddfcfb67b07 , 0xf3100c07ce8d49e3 , 0x1c0841bbd3caf2c7 , 0x11c02bcba311477c , 0xe4eeea3e81bee2f5 , 0xe99377b3d4f14351 , 0x94cf6b6aa44f682 , 0xeff578b580efa5ba ,
                                0x783fe4519e682712 , 0x3ad650599824c658 , 0x5f4fa3f2a7695a94 , 0x92238ff64e968737 , 0x9c65339772373a74 , 0xddb8dfefd27b6b70 , 0xdfa95ed006e49422 , 0x665f2a9704620e92 , 0x6e0cb318337dde01 , 0xe2dda755cd2df423 , 0x5c89fab60ddfa902 , 0xa0c37e5c1c5d32f3 ,
                                0x4ab2e712213f267a , 0x4d7c0f1d77d21613 , 0xeae98e45ca324aea , 0xe16870767dc9fdb3 , 0xe9a752f7373349d6 , 0xde1b0c63b278a439 , 0x55806d6083b27be5 , 0x1c8266c5144a8041 , 0xd918ecb938e507d3 , 0x79b312b924635a70 , 0x29075cfc71aa3007 , 0x332778a53cafe641 ,
                                0x6baaba6775f8c1c8 , 0x5fb97c1b9960cf32 , 0xfa40b5c8e6672062 , 0xf33e1053515d47f7 , 0x5b10771b498995be , 0x89923fff7fc5cfa2 , 0xae485aa4c2ecc339 , 0x7d147ddd4057a0e5 , 0xac326c3636af90bf , 0xd5eac267410929cc , 0xe5acd7e2e4c61d74 , 0x651e2ca1f4ed0eb0 ,
                                0x295b3bed241ecc6f , 0x3a7c940e8efb292a , 0xe2cf105e1ff9e155 , 0x105adc627effbc49 , 0x9eea8a2658eb8bda , 0xfeb72ca15fa0c968 , 0x3c0b8d5fb7198e6a , 0xf1e4eee401ee9d4a , 0xef1360a77c69ab8d , 0x39d37805f1ae6369 , 0x922a5653637506c3 , 0xa8280b2055205d9f ,
                                0x891f9b8ffb3278e9 , 0xb6cd5fb553a0588b , 0x4b97e54cdf6d4d66 , 0x603f4706e02d2967 , 0x78bc3b28534144b5 , 0xa8c6e92507750028 , 0x8ce59d5c84e3e201 , 0x2dfc38ccdcaa311a , 0xd9ce67fee93ac4f3 , 0x5252723fbd095b5e , 0x8f11d7b571cf6de0 , 0xcf14a0d007900ded ,
                                0xd5506653a8cc99f6 , 0xda2544ed7d0e5311 , 0xec18ac9fc4ec361f , 0x97f9cd062c49ea73 , 0x43b4c5d5922f0ab1 , 0x2fb22aadfea8042f , 0xd24d0d41648f0721 , 0x40d6a6fe93589386 , 0x7953eab0b6c7cc53 , 0x5a2bb94081a3de33 , 0x36f8132f61978d42 , 0x61360d737ea45566 ,
                                0xd9607cea06eb6911 , 0xe46ec15e675317ed , 0x28c27ad5a8804ec9 , 0x70d1aa69fd614921 , 0xe3e33b0d32be9a44 , 0x559881e4083e82 , 0xa648daa5291bb21 , 0x4c0866e4819af633 , 0xbb403d28403ba9b5 , 0x93f106c0c32be2b0 , 0xd61f1133c9358349 , 0x127cad23015e6c6f ,
                                0x5c2c51ad8502e35 , 0xeb2cb1b557f92854 , 0x527b9fdd4d672f8a , 0xe5b1a734d85ba1e , 0x77b2a9312d20b771 , 0x60580d7614dabc2f , 0x68d4a09b5545a66a , 0x2ac8d193a81f6266 , 0xea7016117b6c3d05 , 0x4619ac9fe35e73e5 , 0x3627026191c718de , 0xc7fa6ea2047937ee ,
                                0xbd17d4f9890c64d0 , 0xa549786f36d51c47 , 0xa6a950678e8887c4 , 0xd3720d9ebacc3fc1 , 0xe330b34c62967489 , 0xc93349e7b388b9d4 , 0x34ad443dfdc25691 , 0xf2e5c47bd9838071 , 0x7ddf786d3a208290 , 0x3cc18d0ea4993f7b , 0x9b47aab1e2581f47 , 0xc84ea1bf9e28e17e ,
                                0xa42306ed69223a07 , 0x330f47335a73ffa4 , 0xd54120852a0c3bab , 0x3d9e90b4ffecfef7 , 0x699f60ab7744621 , 0xfde309486bef5b6f , 0x88cedbefe9d0b7b6 , 0xae9f742b95d1955f , 0xf34dc07a6976b8bb , 0xac91674bb404743c , 0x189227f80e39a14a , 0x5f78f8ca8275e9d3 ,
                                0xc6089587774e802a , 0x5c73dc08629636c , 0xa626694b20fe927 , 0x765faff02f7d526a , 0xf9b0497eaf4c4055 , 0x66bc3e38f34a3c67 , 0x2c5c5ea42d01c91d , 0x86eb7423029b42dd , 0x872cb26ca5692304 , 0xfa4d8bed19645cdf , 0xd8baaaafcc75e384 , 0x85954814163c8169 ,
                                0x6524e2a31edf379 , 0x280616597becf54 , 0x60f7ad83487d0fea , 0x31df112ddfd267f3 , 0x2d585eb9612f993d , 0x56ec683421c5c3d9 , 0xb4218ee6e5090d , 0x5da0beb74dba556b , 0xb35419f25677c63d , 0x528ddbbc8a84e317 , 0x70e9481d9e67f009 , 0xefff9e8346cab373 ,
                                0xf23e1980c3ffec17 , 0x4380600d42beff91 , 0xebe00d5aec0158d4 , 0x9a8c9032957b3441 , 0xecfe48313a184caf , 0x772225c9e3a9e927 , 0x5a7286272c5e53e7 , 0x9f0ad80468af2cc2 , 0x6600d98c2f683a06 , 0xc51ce421404966dd , 0xeb141cbb6b70a93f , 0x5c5e2237b41eaf01 ,
                                0xaad248c58450594c , 0xa3d9e1da57659ade , 0x2b2171213c1fb885 , 0x6121b7fb5a62c8c9 , 0x31442bf8a36bfd35 , 0x68db9669e02954bd , 0xf2fa22740a1b3289 , 0xda6596f12a9c8a87 , 0x5a99d8b40132eb8a , 0x8f801c1c8b5895fc , 0x4d6025fa37cc9ff6 , 0xad16ec3bdbc33a72 ,
                                0x593c26d8dcbca201 , 0xd8ac5c50f32dccd0 , 0xaa101063a6ae942 , 0x908ce422cf8957ef , 0x9d772ec5c3a36e50 , 0xedde0ebf13cf0924 , 0x7805caadc62953e4 , 0xf8c04f41c6e8d32f , 0x5bd4fd4fb01ed7d , 0xa2634d2466eafdd , 0x6c0bea4efc8c28cb , 0x66a90e49d24f9d1c ,
                                0x36f51c288f994678 , 0xc38bca1218fe705d , 0x8fe5b7e42ed9f80b , 0x5d45c552a7657374 , 0xb94c96c92f11b3ed , 0x2756529abc8e004b , 0x96c27329e6acadda , 0x31c967bba6778d34 , 0x5e16c1100c5cb154 , 0x93bfe0a6a444e193 , 0xbb5f9692c6a56cbd , 0xc5723d9cf9840b38 ,
                                0x3b2f84673136df4b , 0xa1905a274ef8b6a9 , 0x7460bb0e753c60fc , 0x4f87b3c756e1d121 , 0x506835543ec8f326 , 0xd81f376e956c6914 , 0x67f0119c23b4815c , 0xb6025757518b2a78 , 0x737c3cd5ff6bc5c4 , 0x3e3e63e6f724a628 , 0xf2747b1e32df10e , 0x2b584dd441096011 ,
                                0xc70d6511cb8955a6 , 0x528d19dd3fe7f613 , 0x31bfdb6f99d476e3 , 0xdff5cae2aafaa1b3 , 0xa928f650a39ed03c , 0xcdb14258ffd2f11c , 0x8a8b74a5ca34bdc3 , 0x9dda1483b84267f7 , 0x7dd3214b415d767f , 0x38fb920670155728 , 0x2d3467a9beaf525e , 0xfcded6e7dfcc326f ,
                                0x521ce3c841ef70c6 , 0x9bf04c2e3e4c0d7e , 0x8dc6b6f94b071221 , 0x962658ced0fbc609 , 0x9c3ee4882b55e5d3 , 0xbb3b04bf187b46cd , 0x527fb8b376167f6d , 0x3531f17947b3cfb3 , 0x253f9382aeee692d , 0x1b88ea67b3a6596c , 0xd06754d8bd9daf04 , 0x5d20d128d3ff0f40 ,
                                0x709e6b742b1414b3 , 0x62cab1bda70b87e3 , 0x3b3001634639c2c5 , 0x963d327f5e6e8b , 0x1e8901ba0de0616e , 0xea5f8a7815ff3fa8 , 0x88dfd12c2971a599 , 0x72c7f09d99aea8db , 0xbd17c1805b0d93a8 , 0x3ca7b7b88261922b , 0x51c05a9d33ec7cae , 0x35025757b4e688 ,
                                0x7511df3e76fa4e3b , 0x7ed46341beec15 , 0xdd176b39c5bf81e4 , 0xa58461f18d4770dc , 0x26b9c18378c9212d , 0x1d1e3c88af02cecd , 0xc327ecf126e3bb86 , 0x30aebf56d18623d , 0xa322ac1425a3a77a , 0xa8e7c4dd92d7903d , 0x44f9b24481c5453b , 0xe379c6c2d81ff689 ,
                                0xe68bca57d71e0831 , 0x7d9899461c9de4d5 , 0x926aae3c95f69e3d , 0x44360902e6a4dfc2 , 0x60456614eeb6eec4 , 0x34626b6ca60637ce , 0xaf06ed2c950330c9 , 0x85d5daa834e8c2ec , 0x5c9d877e1878ce9a , 0xc46faa6b9b4c15b1 , 0x3e293349fb5e86d7 , 0x347917f1d704135 ,
                                0xbd540b8fbebe85e7 , 0x664ccc8682102d18 , 0x16e3960e977ae00c , 0x620ba50eaedb154 , 0xf5174dbbb11433bd , 0xf6bb23f3f8d1a9b5 , 0x5830357090f61cee , 0x6932f926bcaed34 , 0xd288d1e7e038d564 , 0x3b6b87b3a906ed91 , 0xbde8e9e4a1f0b357 , 0x1d8d4ea63152d7d2 ,
                                0xcf49cbba313ffee8 , 0x420c97ac5daec97 , 0xdf090c34d47aa02d , 0x177eecade47d7f64 , 0x3f8f103609d4c2f1 , 0xcaba01ab91842e51 , 0x35b48c25762a0a51 , 0xce491be9fa56ffbd , 0xc6be4ea9179b9dd8 , 0x5ca52a5dc33fb9f3 , 0xe989bae853cb0ad6 , 0x58d362abb20c08ee ,
                                0x8d921de834b477f8 , 0x9039d27847ebf096 , 0x5cb8be64af304e74 , 0x66cbb4d666932e2e , 0x5e469adc6b5a9343 , 0x707b21dab74119c7 , 0xf46492494128043c , 0x370b90ef9df560fc , 0xd34de560baaaf816 , 0x41c33794b7aca641 , 0x1ccbcbf3f98ccd8e , 0x5f2791bfe039bc84 ,
                                0xd0cf86d5e81354f , 0x29d45b306acaecf8 , 0xa1b866238f75a34a , 0x52a515857ff00540 , 0x5b1f2a973c7d879d , 0xedd4aa0b5c7f6658 , 0xdbb90980538b6444 , 0x60598bb31e5800e1 , 0xcda413da3825bc18 , 0x80b079bf0eb1a9cc , 0xdaa0d6eed67800fa , 0x84700a42952e8a6e ,
                                0x7b12c5b850256213 , 0x8463d899dba5b182 , 0xfdd048b5557a788a , 0xa598db95901506ab , 0xaf1752a5c6b1202f , 0xe8ae0527c8f5286e , 0xc2c58f713f169adf , 0xbdf05e5bf9d1cbd , 0xef671c6370a40b1 , 0xa9ac05ccc52bc68d , 0x7a757fda81e9c42c , 0x57a77d466ff1d70c};

const U64 BlackSideKey = 0x7fa7bf89a1dc915;

const U64 EnpassentFileKeys[8] = {0xe8da396ca9feff6d , 0xedeb165c779a859c , 0x17570135ad20906a , 0xf467ef36dc48b0e4 , 0x2ff8a23bd2886eb , 0x32b125755debef48 , 0xe22196bcff07d173 , 0x6b79b53fc6380bc4};

const U64 CastlingKeys[16] = {0x3d803b1089e1f03d , 0xc78233f02feeef6a , 0x767fc022a6d98235 , 0x78e5da961aedbacf , 0x8d975a2d0cfc6b31 , 0x89c0dfe711547ad1 , 0x22ce232a684c9411 , 0xc069d2cd2cdf7927 , 0x3fa0f374d9b63b4 , 0x5c386b991de07296 , 0xf6933ee6486187e2 , 0x9df37250c39d7c7 , 0x5f6230aa1c900797 , 0xfa5c90ecef97b0e , 0x2ee62184bcf745d , 0x1a581c7850437c9d};

/* Methods */

void Generate_HashKey(Board *);


#endif // HASHKEY_H_INCLUDED
