#include "util.h"

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

IpAddress ParseIpAddress(const char *input)
{
    size_t length = strlen(input);
    assert(length < 16);
    char buf[4] = {0, 0, 0, 0};

    IpAddress result = {{0, 0, 0, 0}};

    for (int i = 0, buf_idx = 0, result_idx = 0; i < length; i++)
    {
        char cur = input[i];

        if (cur == '.')
        {
            int val = atoi(buf);
            assert(val < 256 && val >= 0);
            result.Address[result_idx] = (char)val;
            result_idx++;
            buf_idx = 0;
            buf[0] = 0;
            buf[1] = 0;
            buf[2] = 0;
            continue;
        }

        assert(isdigit(cur));
        assert(buf_idx < IP_ADDRESS_SIZE);
        buf[buf_idx] = cur;
        buf_idx++;
    }

    int val = atoi(buf);
    assert(val < 256 && val >= 0);
    result.Address[IP_ADDRESS_SIZE - 1] = (char)val;

    return result;
}