int reverseBits(int n) {
    unsigned int n2=(unsigned int)n;

    //swap 1bit. 1010
    n2=((n2&0xaaaaaaaa)>>1)|((n2&0x55555555)<<1);
    //swap 2bit (11001100)==>0xc0c0, 0011
    n2=((n2&0xcccccccc)>>2)|((n2&0x33333333)<<2);
    //swap 4bit (11110000)==>0xf0, 000011111
    n2=((n2&0xf0f0f0f0)>>4)|((n2&0xf0f0f0f)<<4);
    //swap 8bit (11111111)==>0xf0, 000011111
    n2=((n2&0xff00ff00)>>8)|((n2&0x00ff00ff)<<8);
    //swap 16bit 
    n2=((n2&0xffff0000)>>16)|((n2&0x0000ffff)<<16);

    return n2;
}
