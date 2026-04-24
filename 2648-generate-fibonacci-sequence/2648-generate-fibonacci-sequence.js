/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let x = 0, y = 1;

    yield x;
    yield y;

    while (true) {
        let next = x + y;
        x = y;
        y = next;
        yield y;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */