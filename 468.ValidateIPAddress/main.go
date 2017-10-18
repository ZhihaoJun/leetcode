package main

import "log"

/*
IPv4 = v4Part . v4Part . v4Part . v4Part
v4Part = 2 dmax5 dmax5
       = 2 digit
       = 2
       = 1 digit digit
       = 1 digit
       = 1
       = 0
       = 3 | 4 | 5 | 6 | 7 | 8 | 9 digit
       = 3 | 4 | 5 | 6 | 7 | 8 | 9
dmax5 = 0 | 1 | 2 | 3 | 4 | 5
digit = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

IPv6 = v6Part : v6Part : v6Part : v6Part : v6Part : v6Part : v6Part : v6Part
v6Part = hex hex hex hex
       = hex hex hex
       = hex hex
       = hex
hex = digit | a | b | c | d | e | f | A | B | C | D | E | F
*/

type IPv4DFA struct {
	str string
}

func NewIPv4DFA(str string) *IPv4DFA {
	return &IPv4DFA{
		str: str,
	}
}

func (a *IPv4DFA) Match() (int, bool) {
	cur := 0
	if n, matched := a.v4Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, '.') {
		cur++
	} else {
		return 0, false
	}

	if n, matched := a.v4Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, '.') {
		cur++
	} else {
		return 0, false
	}

	if n, matched := a.v4Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, '.') {
		cur++
	} else {
		return 0, false
	}

	if n, matched := a.v4Part(cur); matched {
		cur += n
		return cur, true
	} else {
		return 0, false
	}
}

func (a *IPv4DFA) v4Part(pos int) (int, bool) {
	if pos >= len(a.str) {
		return 0, false
	}
	switch a.str[pos] {
	case '0':
		return 1, true
	case '1':
		if a.digit(pos + 1) {
			if a.digit(pos + 2) {
				return 3, true
			}
			return 2, true
		}
		return 1, true
	case '2':
		if a.dmax5(pos + 1) {
			if a.dmax5(pos + 2) {
				return 3, true
			}
			return 2, true
		} else if a.digit(pos + 1) {
			return 2, true
		}
	case '3', '4', '5', '6', '7', '8', '9':
		if a.digit(pos + 1) {
			return 2, true
		}
		return 1, true
	}
	return 0, false
}

func (a *IPv4DFA) digit(pos int) bool {
	return pos < len(a.str) && a.str[pos] >= '0' && a.str[pos] <= '9'
}

func (a *IPv4DFA) dmax5(pos int) bool {
	return pos < len(a.str) && a.str[pos] >= '0' && a.str[pos] <= '5'
}

func (a *IPv4DFA) match(pos int, c uint8) bool {
	return pos < len(a.str) && a.str[pos] == c
}

type IPv6DFA struct {
	str string
}

func NewIPv6DFA(str string) *IPv6DFA {
	return &IPv6DFA{
		str: str,
	}
}

func (a *IPv6DFA) Match() (int, bool) {
	cur := 0
	if n, matched := a.v6Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, ':') {
		cur++
	} else {
		return 0, false
	}

	if n, matched := a.v6Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, ':') {
		cur++
	} else {
		return 0, false
	}

	if n, matched := a.v6Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, ':') {
		cur++
	} else {
		return 0, false
	}

	// 4
	if n, matched := a.v6Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, ':') {
		cur++
	} else {
		return 0, false
	}
	if n, matched := a.v6Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, ':') {
		cur++
	} else {
		return 0, false
	}

	if n, matched := a.v6Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, ':') {
		cur++
	} else {
		return 0, false
	}

	if n, matched := a.v6Part(cur); matched {
		cur += n
	} else {
		return 0, false
	}
	if a.match(cur, ':') {
		cur++
	} else {
		return 0, false
	}

	if n, matched := a.v6Part(cur); matched {
		cur += n
		return cur, true
	} else {
		return 0, false
	}
}

func (a *IPv6DFA) v6Part(pos int) (int, bool) {
	if a.hex(pos) {
		if a.hex(pos + 1) {
			if a.hex(pos + 2) {
				if a.hex(pos + 3) {
					return 4, true
				}
				return 3, true
			}
			return 2, true
		}
		return 1, true
	}
	return 0, false
}

func (a *IPv6DFA) hex(pos int) bool {
	return pos < len(a.str) && ((a.str[pos] >= '0' && a.str[pos] <= '9') || (a.str[pos] >= 'a' && a.str[pos] <= 'f') || (a.str[pos] >= 'A' && a.str[pos] <= 'F'))
}

func (a *IPv6DFA) match(pos int, c uint8) bool {
	return pos < len(a.str) && a.str[pos] == c
}

func validIPAddress(IP string) string {
	n, ipv4 := NewIPv4DFA(IP).Match()
	if n == len(IP) && ipv4 {
		return "IPv4"
	}
	n, ipv6 := NewIPv6DFA(IP).Match()
	if n == len(IP) && ipv6 {
		return "IPv6"
	}
	return "Neither"
}

type Case struct {
	IP     string
	Result string
}

func main() {
	cases := []Case{
		Case{
			IP:     "192.168.0.1",
			Result: "IPv4",
		},
		Case{
			IP:     "192.168.00.1",
			Result: "Neither",
		},
		Case{
			IP:     "256.168.00.1",
			Result: "Neither",
		},
		Case{
			IP:     "2001:0db8:85a3:0000:0000:8a2e:0370:7334",
			Result: "IPv6",
		},
		Case{
			IP:     "2001:db8:85a3:0:0:8A2E:0370:7334",
			Result: "IPv6",
		},
		Case{
			IP:     "2001:0db8:85a3::8A2E:0370:7334",
			Result: "Neither",
		},
		Case{
			IP:     "001:0db8:85a3:0:8A2E:0370:7334:0",
			Result: "IPv6",
		},
		Case{
			IP:     "02001:0db8:85a3:0000:0000:8a2e:0370:7334",
			Result: "Neither",
		},
		Case{
			IP:     "2001:db8:85a3:0:0:8A2E:0370:7334192.168.0.1",
			Result: "Neither",
		},
		Case{
			IP:     "192.168.0.12001:db8:85a3:0:0:8A2E:0370:7334",
			Result: "Neither",
		},
		Case{
			IP:     "",
			Result: "Neither",
		},
		Case{
			IP:     "1",
			Result: "Neither",
		},
		Case{
			IP:     "0.0.0.0",
			Result: "IPv4",
		},
		Case{
			IP:     "0.0.0.a",
			Result: "Neither",
		},
	}
	for _, c := range cases {
		result := validIPAddress(c.IP)
		if result != c.Result {
			log.Println("Case failed")
			log.Println(c)
			log.Println("output is", result)
		}
	}
	log.Println("Test Over")
}
