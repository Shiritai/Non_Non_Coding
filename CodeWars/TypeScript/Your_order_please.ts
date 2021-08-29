function order(words: string): string {
    return words.split(" ")
                .sort((a, b) => getNum(a) - getNum(b))
                .join(' ');
}

function getNum(str: string): number {
    let num = /^[0-9]*$/.exec(str);
    return parseInt(num ? num.toString() : '0');
}