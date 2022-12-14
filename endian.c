/*
 * endian.c
 *
 * Simple helper functions for reading and writing BE and LE numbers
 *
 * Copyright (c) 2004 Steve McIntyre <steve@einval.com>
 *
 * GPL v2 - see COPYING
 */

#include "endian.h"

/* Write a 64-bit quantity out into memory in BIG ENDIAN order */
void write_be64(unsigned long long in, unsigned char *out)
{
    out[0] = (in >> 56) & 0xFF;
    out[1] = (in >> 48) & 0xFF;
    out[2] = (in >> 40) & 0xFF;
    out[3] = (in >> 32) & 0xFF;
    out[4] = (in >> 24) & 0xFF;
    out[5] = (in >> 16) & 0xFF;
    out[6] = (in >> 8) & 0xFF;
    out[7] = in & 0xFF;
}

/* Read in a 64-bit BIG ENDIAN quantity */
unsigned long long read_be64(unsigned char *in)
{
    unsigned long long result = 0;

    result |= (unsigned long long)in[0] << 56;
    result |= (unsigned long long)in[1] << 48;
    result |= (unsigned long long)in[2] << 40;
    result |= (unsigned long long)in[3] << 32;
    result |= (unsigned long long)in[4] << 24;
    result |= (unsigned long long)in[5] << 16;
    result |= (unsigned long long)in[6] << 8;
    result |= (unsigned long long)in[7];
    
    return result;
}

/* Write a 64-bit quantity out into memory in LITTLE ENDIAN order */
void write_le64(unsigned long long in, unsigned char *out)
{
    out[0] = in & 0xFF;
    out[1] = (in >> 8) & 0xFF;
    out[2] = (in >> 16) & 0xFF;
    out[3] = (in >> 24) & 0xFF;
    out[4] = (in >> 32) & 0xFF;
    out[5] = (in >> 40) & 0xFF;
    out[6] = (in >> 48) & 0xFF;
    out[7] = (in >> 56) & 0xFF;
}

/* Read in a 64-bit LITTLE ENDIAN quantity */
unsigned long long read_le64(unsigned char *in)
{
    unsigned long long result = 0;

    result |= (unsigned long long)in[0];
    result |= (unsigned long long)in[1] << 8;
    result |= (unsigned long long)in[2] << 16;
    result |= (unsigned long long)in[3] << 24;
    result |= (unsigned long long)in[4] << 32;
    result |= (unsigned long long)in[5] << 40;
    result |= (unsigned long long)in[6] << 48;
    result |= (unsigned long long)in[7] << 56;
    
    return result;
}

/* Write a 48-bit quantity out into memory in LITTLE ENDIAN order */
void write_le48(unsigned long long in, unsigned char *out)
{
    out[0] = in & 0xFF;
    out[1] = (in >> 8) & 0xFF;
    out[2] = (in >> 16) & 0xFF;
    out[3] = (in >> 24) & 0xFF;
    out[4] = (in >> 32) & 0xFF;
    out[5] = (in >> 40) & 0xFF;
}

/* Read in a 48-bit LITTLE ENDIAN quantity */
unsigned long long read_le48(unsigned char *in)
{
    unsigned long long result = 0;

    result |= (unsigned long long)in[0];
    result |= (unsigned long long)in[1] << 8;
    result |= (unsigned long long)in[2] << 16;
    result |= (unsigned long long)in[3] << 24;
    result |= (unsigned long long)in[4] << 32;
    result |= (unsigned long long)in[5] << 40;
    
    return result;
}

/* Write a 32-bit quantity out into memory in BIG ENDIAN order */
void write_be32(unsigned long in, unsigned char *out)
{
    out[0] = (in >> 24) & 0xFF;
    out[1] = (in >> 16) & 0xFF;
    out[2] = (in >> 8) & 0xFF;
    out[3] = in & 0xFF;
}

/* Read in a 32-bit BIG ENDIAN quantity */
unsigned long read_be32(unsigned char * in)
{
    unsigned long result = 0;

    result |= (unsigned long)in[0] << 24;
    result |= (unsigned long)in[1] << 16;
    result |= (unsigned long)in[2] << 8;
    result |= (unsigned long)in[3];
    
    return result;
}

/* Write a 32-bit quantity out into memory in LITTLE ENDIAN order */
void write_le32(unsigned long in, unsigned char *out)
{
    out[0] = in & 0xFF;
    out[1] = (in >> 8) & 0xFF;
    out[2] = (in >> 16) & 0xFF;
    out[3] = (in >> 24) & 0xFF;
}

/* Read in a 32-bit LITTLE ENDIAN quantity */
unsigned long read_le32(unsigned char *in)
{
    unsigned long result = 0;

    result |= (unsigned long)in[0];
    result |= (unsigned long)in[1] << 8;
    result |= (unsigned long)in[2] << 16;
    result |= (unsigned long)in[3] << 24;
    
    return result;
}

/* Write a 16-bit quantity out into memory in BIG ENDIAN order */
void write_be16(unsigned short in, unsigned char *out)
{
    out[0] = (in >> 8) & 0xFF;
    out[1] = in & 0xFF;
}
    
/* Read in a 16-bit BIG ENDIAN quantity */
unsigned short read_be16(unsigned char *in)
{
    unsigned short result = 0;
    
    result |= (unsigned short)in[0] << 8;
    result |= (unsigned short)in[1];
    return result;
}

/* Write a 16-bit quantity out into memory in LITTLE ENDIAN order */
void write_le16(unsigned short in, unsigned char *out)
{
    out[0] = in & 0xFF;
    out[1] = in & 0xFF >> 8;
}
    
/* Read in a 16-bit LITTLE ENDIAN quantity */
unsigned short read_le16(unsigned char *in)
{
    unsigned short result = 0;
    
    result |= (unsigned short)in[0];
    result |= (unsigned short)in[1] << 8;
    return result;
}

