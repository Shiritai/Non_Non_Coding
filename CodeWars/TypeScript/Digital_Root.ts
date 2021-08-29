const digitalRoot = (n: number): number => {
    let tmp = n;
    do {
        let cur = Array.from(tmp.toString(), (s) => parseInt(s));
        tmp = 0;
        for (let i = 0; i < cur.length; ++i)
            tmp += cur[i];
    } while (tmp > 9);
    return tmp;
};

/** 
 ** SUPER CLEVER ANSWER!!!
 ** https://mathworld.wolfram.com/DigitalRoot.html
 **/
function superCleverDigitalRoot(n: number): number {
    return (n - 1) % 9 + 1;
}
