#include "ByteOrder.h"

ByteOrder::NATIVE_BYTE_ORDER ByteOrder::GetLocalByteOrder ()
{
	assert(sizeof(UINT16) == 2);

	union
	{
		UINT16 s;
		byte c[sizeof(UINT16)];
	} un;
	un.s = 0x0201;

	if ( ( 2 == un.c[0] ) && ( 1 == un.c[1] ) )
	{
		return BIG_ENDIAN;
	}
	else if ( ( 1 == un.c[0] ) && ( 2 == un.c[1] ) )
	{
		return LITTLE_ENDIAN;
	}
	else
	{
		assert(false);
		printf("Unknow Byte Order");
	}
}

UINT16 ByteOrder::FlipBytes(UINT16 val)
{
	return (((val >> 8)  & 0x00FF) | ((val << 8)  & 0xFF00));
}

UINT32 ByteOrder::FlipBytes(UINT32 val)
{
	return (
		((val >> 24) &0x000000FF)|
		((val >>  8) & 0x0000FF00)|
		((val <<  8) & 0x00FF0000)|
		((val << 24) & 0xFF000000)
		);
}

UINT64 ByteOrder::FlipBytes(UINT64 val)
{
	UINT32 hi = UINT32( val >> 32);
	UINT32 lo = UINT32(val  & 0xFFFFFFFF);

	UINT64 fhi = UINT64(FlipBytes(hi));
	UINT64 flo = UINT64(FlipBytes(lo));

	flo <<= 32;
	return (flo | fhi);

}


INT64 ByteOrder::FlipBytes(INT64 val)
{
	return FlipBytes(UINT64(val));
}

INT32 ByteOrder::FlipBytes(INT32 val)
{
	return FlipBytes((UINT32)val);
}

INT16 ByteOrder::FlipBytes(INT16 val)
{
	return FlipBytes((UINT16)val);
}
/*

#define DEFINE_NATIVE_T_NET(type)                                                                                \
	type ByteOrder::FromNativeOrderToNetOrder(type val)                                \
{                                                                                                                                \
	if(NativeByteOrder != BIG_ENDIAN)                                                \
	{                                                                                                                \
		val = FlipBytes(val);                                                        \
	}                                                                                                                \
	return val;                                                                                                \
}                                                                                                                                \


DEFINE_NATIVE_T_NET(INT16)
DEFINE_NATIVE_T_NET(UINT16)

DEFINE_NATIVE_T_NET(INT32)
DEFINE_NATIVE_T_NET(UINT32)

DEFINE_NATIVE_T_NET(INT64)
DEFINE_NATIVE_T_NET(UINT64)

#define DEFINE_NET_T_NATIVE(type)                                                                                \
	type ByteOrder::FromNetOrderToNativeOrder(type val)                                \
{                                                                                                                                \
	if(NativeByteOrder != BIG_ENDIAN)                                        \
	{                                                                                                                \
		val = FlipBytes(val);                                                        \
	}                                                                                                                \
	return val;                                                                                                \
}                                                                                                                                \


DEFINE_NET_T_NATIVE(INT16)
DEFINE_NET_T_NATIVE(UINT16)

DEFINE_NET_T_NATIVE(INT32)
DEFINE_NET_T_NATIVE(UINT32)

DEFINE_NET_T_NATIVE(INT64)
DEFINE_NET_T_NATIVE(UINT64)*/
