
class Solution {
public:
    using u32 = uint32_t;
    auto longestValidParentheses(std::string_view s) const noexcept {
        const u32 n = static_cast<u32>(s.size());
        u32 a = 0, o = 0, l = 0;

        auto step = [&] [[gnu::always_inline]] (bool t) noexcept {
            ++l;
            o += t;
            l &= -u32{!!(t | o)};
            o = std::min(o, o - !t);
            a = std::max(a, l & -u32{!o});
        };

        // Forward pass
        for (u32 i = 0; i != n; ++i)
            step(s[i] == '(');

        // Reverse pass (trimmed)
        u32 stop = n - (l & -u32{!!o});
        o = l = 0;
        for (u32 i = n; i-- != stop;)
            step(s[i] == ')');

        return a;
    }
};
