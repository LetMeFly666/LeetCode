type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };

interface Function {
    callPolyfill(context: Record<string, JSONValue>, ...args: JSONValue[]): JSONValue;
}


Function.prototype.callPolyfill = function(context, ...args): JSONValue {
    
}

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */