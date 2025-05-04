type P = Promise<number>

async function addTwoPromises(promise1: P, promise2: P): P {
    
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */