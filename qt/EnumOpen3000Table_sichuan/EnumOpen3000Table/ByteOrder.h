#ifndef BYTEORDER_H
#define BYTEORDER_H

#include <assert.h>
#include <stdio.h>
#include <QtGlobal>

#define UINT16 quint16
#define UINT32 quint32
#define UINT64 quint64
#define INT16 qint16
#define INT32 qint32
#define INT64 qint64

#define byte quint8


class ByteOrder
{
public:
    enum NATIVE_BYTE_ORDER { BIG_ENDIAN = 0, LITTLE_ENDIAN = 1 };


    NATIVE_BYTE_ORDER GetLocalByteOrder();

    static UINT16 FlipBytes(UINT16 val);
	static INT16 FlipBytes(INT16 val);

	static UINT32 FlipBytes(UINT32 val);
	static INT32 FlipBytes(INT32 val);

	static UINT64 FlipBytes(UINT64 val);
	static INT64 FlipBytes(INT64 val);

/*	static UINT16 FromNativeOrderToNetOrder(UINT16 val);
	static INT16 FromNativeOrderToNetOrder(INT16 val);

	static UINT32 FromNativeOrderToNetOrder(UINT32 val);
	static INT32 FromNativeOrderToNetOrder(INT32 val);

	static UINT64 FromNativeOrderToNetOrder(UINT64 val);
	static INT64 FromNativeOrderToNetOrder(INT64 val);
	//////////////////////////////////////////////////////////////////////////////////

	static UINT16 FromNetOrderToNativeOrder(UINT16 val);
	static INT16 FromNetOrderToNativeOrder(INT16 val);

	static UINT32 FromNetOrderToNativeOrder(UINT32 val);
	static INT32 FromNetOrderToNativeOrder(INT32 val);

	static UINT64 FromNetOrderToNativeOrder(UINT64 val);
    static INT64 FromNetOrderToNativeOrder(INT64 val);*/
};
#endif

