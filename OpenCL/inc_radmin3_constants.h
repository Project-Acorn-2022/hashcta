/**
 * Author......: See docs/credits.txt
 * License.....: MIT
 *
 * Further credits:
 * The password-storage algorithm used by Radmin 3 was analyzed and made public
 * by synacktiv:
 * https://www.synacktiv.com/publications/cracking-radmin-server-3-passwords.html
 */

#ifndef INC_RADMIN3_CONSTANTS_H
#define INC_RADMIN3_CONSTANTS_H

#define PRECOMP_BITS      10
#define PRECOMP_VECLEN   160 // SHA1 hash (in bits, 20 bytes)
#define PRECOMP_SLOTS    (PRECOMP_VECLEN / PRECOMP_BITS)
#define PRECOMP_ENTRIES  (1 << PRECOMP_BITS) // 2 ^ PRECOMP_BITS
#define PRECOMP_ENTRYLEN 256 / 4 // data len in u32 (therefore divided by 4 bytes)
#define PRECOMP_DATALEN  (PRECOMP_ENTRIES - 1) * PRECOMP_SLOTS * PRECOMP_ENTRYLEN
#define PRECOMP_MASK     0xffffffff >> (32 - PRECOMP_BITS)

CONSTANT_VK u32 RADMIN3_M[128] =
{
  0x740a682f, 0x7b379fd7, 0x4af5b8d3, 0xd70b2bca, 0xd7f51544, 0xe5a4ccf5,
  0x24c9e5a2, 0x30ebc4fd, 0x40a71f19, 0xfaa0c43b, 0x2bfe7dba, 0xac9278b9,
  0x97245bd2, 0x9c4d18f6, 0x89dfd06c, 0x6091acea, 0x8ba2332d, 0x2cfb3b52,
  0x5350dec7, 0x34fd0fd4, 0x125db8ad, 0x149167ea, 0x01f560dd, 0x0fdbaf46,
  0x6b0c6bdb, 0xc5473fdb, 0x36fc4f80, 0xb8f90dea, 0x48598f2c, 0x590387f5,
  0xe63ec4b3, 0x021c881a, 0xa0d18a79, 0xbdd952f7, 0xe99e6127, 0xedbba5ea,
  0x102fc6ce, 0xf8bdd56a, 0x66261cd3, 0xdb701022, 0x0db4db96, 0x2d7cdf81,
  0x2cbdd4ac, 0xca9f0806, 0x5503342e, 0x81a32da9, 0xfd0f9e29, 0xffd8df96,
  0x4dd09947, 0xef2fcd2a, 0x0dfe4178, 0x86b0dbe6, 0x92cf3357, 0x8e0c3bff,
  0x53e36fb6, 0xcafca04a, 0x3e2cec58, 0x13b406f2, 0xd4304b01, 0xaec0b980,
  0x587d8f77, 0x5d02f19d, 0x0f891dfd, 0x9847fc7e, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000,
};

CONSTANT_VK u32 RADMIN3_R[64] =
{
  0x8bf597d1, 0x84c86028, 0xb50a472c, 0x28f4d435, 0x280aeabb, 0x1a5b330a,
  0xdb361a5d, 0xcf143b02, 0xbf58e0e6, 0x055f3bc4, 0xd4018245, 0x536d8746,
  0x68dba42d, 0x63b2e709, 0x76202f93, 0x9f6e5315, 0x745dccd2, 0xd304c4ad,
  0xacaf2138, 0xcb02f02b, 0xeda24752, 0xeb6e9815, 0xfe0a9f22, 0xf02450b9,
  0x94f39424, 0x3ab8c024, 0xc903b07f, 0x4706f215, 0xb7a670d3, 0xa6fc780a,
  0x19c13b4c, 0xfde377e5, 0x5f2e7586, 0x4226ad08, 0x16619ed8, 0x12445a15,
  0xefd03931, 0x07422a95, 0x99d9e32c, 0x248fefdd, 0xf24b2469, 0xd283207e,
  0xd3422b53, 0x3560f7f9, 0xaafccbd1, 0x7e5cd256, 0x02f061d6, 0x00272069,
  0xb22f66b8, 0x10d032d5, 0xf201be87, 0x794f2419, 0x6d30cca8, 0x71f3c400,
  0xac1c9049, 0x35035fb5, 0xc1d313a7, 0xec4bf90d, 0x2bcfb4fe, 0x513f467f,
  0xa7827088, 0xa2fd0e62, 0xf076e202, 0x67b80381,
};

CONSTANT_VK u32 RADMIN3_FACT[64] =
{
  0xfdac2131, 0x56654c77, 0x3e4a8d19, 0x5a1a861c, 0x7906adbd, 0x89d806d0,
  0x26a253a8, 0xcb8c8be2, 0xb62eb887, 0xa2364fb0, 0xbff19140, 0x79aa7301,
  0x78ee9576, 0x554ba4e6, 0xa4f3efd8, 0x7637a767, 0xb413facb, 0xf333933b,
  0xb50a03bc, 0xf100305f, 0x0e3d5ca2, 0x57c949a8, 0x4e73b61d, 0xced3203c,
  0x578439b1, 0x37ed2593, 0x8fb7c6d4, 0x7cb1f2ab, 0xc035c148, 0xd9defd19,
  0x04bf254a, 0xcb970a46, 0xf2a7960c, 0x69a651f6, 0x6adc8010, 0x9e05042d,
  0x4e56ef9d, 0x595b31c9, 0x3f455d15, 0xf703c3e3, 0x3f164848, 0xe4bd5f3a,
  0x62101b16, 0x01138387, 0xf346380e, 0x2358d5cd, 0xc839e279, 0xa31123b1,
  0x45f240ea, 0xe39f2352, 0x91e590cb, 0x6d11e378, 0x04e89126, 0x904b2390,
  0xa11b556d, 0xb6d7dcfb, 0x6e826c53, 0x1392b6e4, 0xa76eefe9, 0x6c770e4d,
  0x0312ac4d, 0x73aa4ff4, 0x39ad3b1f, 0xfad6fce6,
};

#endif // INC_RADMIN3_CONSTANTS_H
