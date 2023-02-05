func formatDuration(_ seconds: Int) -> String {
    if (seconds == 0) {
        return "now"
    }
    let target = [(seconds / (3600 * 24 * 365), "year"), 
        ((seconds / (3600 * 24)) % 365, "day"), 
        ((seconds / 3600) % 24, "hour"), 
        ((seconds / 60) % 60, "minute"), 
        (seconds % 60, "second")].filter{ $0.0 != 0 }
    let concatenate = [String](repeating: ", ", count: target.endIndex) + [" and ", ""];
    return zip(target, concatenate[(concatenate.endIndex - target.endIndex)...])
        .reduce("") { 
            $0 + "\($1.0.0 != 0 ? "\($1.0.0) \($1.0.1)\($1.0.0 != 1 ? "s" : "")\($1.1)" : "")" }
}

print(formatDuration(127262))