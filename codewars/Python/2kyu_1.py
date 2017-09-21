import struct

mapp = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+,./:;<=>?@[]^_`{|}~"'
dmapp = dict((v,k) for k,v in enumerate(mapp))

def b91decode(strng):
    dbq = 0
    dn = 0
    dv = -1
    res = bytearray()
    for s in strng:
        if not s in dmapp.keys():
            continue
        if dv == -1:
            dv = dmapp[s]
        else:
            dv += dmapp[s] * 91
            dbq |= dv << dn
            if dv & 8191 > 88:
                dn += 13
            else:
                dn += 14                
            while True:
                res += struct.pack('B', dbq & 255)
                dbq >>= 8
                dn -= 8
                if dn <= 7:
                    break
            dv = -1
    if dv != -1:
        res += struct.pack('B', (dbq | dv << dn) & 255)
        
    return res.decode('utf-8') 
            
    
def b91encode(strng):
    en = 0
    ebq = 0
    res = ''
    for i in range(len(strng)):
        ebq |= (struct.unpack('B', strng[i].encode())[0] & 255) << en
        en += 8
        if en > 13:
            ev = ebq & 8191
            if ev > 88:
                ebq >>= 13
                en -= 13
            else:
                ev = ebq & 16383
                ebq >>= 14
                en -= 14
            res += mapp[ev % 91] + mapp[ev // 91]
    if en:
        res += mapp[ebq % 91];
        if en > 7 or ebq > 90:
            res += mapp[ebq / 91]

    return res