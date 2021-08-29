type BIT = false | true;
type STATE = [BIT, BIT];
function read(commands: string []): boolean {
    let state: STATE = [false, false]; // init state
    commands.forEach((num: string) => {
        let newState: STATE = [false, false];
        newState[0] = (num == '0') && !state[0] && state[1];
        newState[1] = ((num == '1') && !state[0]) || (state[0] && !state[1]);
        state = newState;
    });
    return !state[0] && state[1];
}

console.log(read(['0']));
console.log(read(['1']));
console.log(read(['1', '0', '0', '1']));