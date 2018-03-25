/**************************************************************************
   Copyright (c) 2017 sewenew

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 *************************************************************************/

#ifndef SEWENEW_REDISPLUSPLUS_COMMAND_H
#define SEWENEW_REDISPLUSPLUS_COMMAND_H

#include <string>
#include <chrono>
#include "connection.h"
#include "command_options.h"
#include "utils.h"

namespace sw {

namespace redis {

namespace cmd {

inline void auth(Connection &connection, const StringView &password) {
    connection.send("AUTH %b", password.data(), password.size());
}

inline void info(Connection &connection) {
    connection.send("INFO");
}

inline void ping(Connection &connection) {
    connection.send("PING");
}

inline void ping(Connection &connection, const StringView &msg) {
    // If *msg* is empty, Redis returns am empty reply of REDIS_REPLY_STRING type.
    connection.send("PING %b", msg.data(), msg.size());
}

// STRING commands.

inline void append(Connection &connection, const StringView &key, const StringView &str) {
    connection.send("APPEND %b %b",
                    key.data(), key.size(),
                    str.data(), str.size());
}

inline void bitcount(Connection &connection,
                        const StringView &key,
                        long long start,
                        long long end) {
    connection.send("BITCOUNT %b %lld %lld",
                    key.data(), key.size(),
                    start, end);
}

template <typename Input>
void bitop(Connection &connection,
            BitOp op,
            const StringView &destination,
            Input first,
            Input last);

inline void bitpos(Connection &connection,
                    const StringView &key,
                    long long bit,
                    long long start,
                    long long end) {
    connection.send("BITPOS %b %lld %lld %lld",
                    key.data(), key.size(),
                    bit,
                    start,
                    end);
}

inline void decr(Connection &connection, const StringView &key) {
    connection.send("DECR %b", key.data(), key.size());
}

inline void decrby(Connection &connection, const StringView &key, long long decrement) {
    connection.send("DECRBY %b",
                    key.data(), key.size(),
                    decrement);
}

inline void get(Connection &connection, const StringView &key) {
    connection.send("GET %b",
                    key.data(), key.size());
}

inline void getbit(Connection &connection, const StringView &key, long long offset) {
    connection.send("GETBIT %b %lld",
                    key.data(), key.size(),
                    offset);
}

inline void getrange(Connection &connection,
                        const StringView &key,
                        long long start,
                        long long end) {
    connection.send("GETRANGE %b %lld %lld",
                    key.data(), key.size(),
                    start,
                    end);
}

inline void getset(Connection &connection,
                    const StringView &key,
                    const StringView &val) {
    connection.send("GETSET %b %b",
                    key.data(), key.size(),
                    val.data(), val.size());
}

inline void incr(Connection &connection, const StringView &key) {
    connection.send("INCR %b", key.data(), key.size());
}

inline void incrby(Connection &connection, const StringView &key, long long increment) {
    connection.send("INCRBY %b",
                    key.data(), key.size(),
                    increment);
}

inline void incrbyfloat(Connection &connection, const StringView &key, double increment) {
    connection.send("INCRBYFLOAT %b %f",
                    key.data(), key.size(),
                    increment);
}

template <typename Input>
inline void mget(Connection &connection, Input first, Input last) {
    Connection::CmdArgs args;
    args << "MGET" << std::make_pair(first, last);

    connection.send(args);
}

template <typename Input>
inline void mset(Connection &connection, Input first, Input last) {
    Connection::CmdArgs args;
    args << "MSET" << std::make_pair(first, last);

    connection.send(args);
}

template <typename Input>
inline void msetnx(Connection &connection, Input first, Input last) {
    Connection::CmdArgs args;
    args << "MSETNX" << std::make_pair(first, last);

    connection.send(args);
}

inline void psetex(Connection &connection,
                    const StringView &key,
                    const std::chrono::milliseconds &ttl,
                    const StringView &val) {
    connection.send("PSETEX %b %lld %b",
                    key.data(), key.size(),
                    ttl.count(),
                    val.data(), val.size());
}

void set(Connection &connection,
            const StringView &key,
            const StringView &val,
            const std::chrono::milliseconds &ttl,
            UpdateType type);

inline void setbit(Connection &connection,
                    const StringView &key,
                    long long offset,
                    long long value) {
    connection.send("SETBIT %b %lld %lld",
                    key.data(), key.size(),
                    offset,
                    value);
}

inline void setnx(Connection &connection,
                    const StringView &key,
                    const StringView &val) {
    connection.send("SETNX %b %b",
                    key.data(), key.size(),
                    val.data(), val.size());
}

inline void setex(Connection &connection,
                    const StringView &key,
                    const std::chrono::seconds &ttl,
                    const StringView &val) {
    connection.send("SETEX %b %lld %b",
                    key.data(), key.size(),
                    ttl.count(),
                    val.data(), val.size());
}

inline void setrange(Connection &connection,
                        const StringView &key,
                        long long offset,
                        const StringView &val) {
    connection.send("SETRANGE %b %lld %b",
                    key.data(), key.size(),
                    offset,
                    val.data(), val.size());
}

inline void strlen(Connection &connection, const StringView &key) {
    connection.send("STRLEN %b", key.data(), key.size());
}

// LIST commands.

template <typename Input>
inline void blpop(Connection &connection,
                    Input first,
                    Input last,
                    const std::chrono::seconds &timeout) {
    Connection::CmdArgs args;
    args << "BLPOP" << std::make_pair(first, last) << timeout.count();

    connection.send(args);
}

template <typename Input>
inline void brpop(Connection &connection,
                    Input first,
                    Input last,
                    const std::chrono::seconds &timeout) {
    Connection::CmdArgs args;
    args << "BRPOP" << std::make_pair(first, last) << timeout.count();

    connection.send(args);
}

inline void brpoplpush(Connection &connection,
                        const StringView &source,
                        const StringView &destination,
                        const std::chrono::seconds &timeout) {
    connection.send("BRPOPLPUSH %b %b %lld",
                    source.data(), source.size(),
                    destination.data(), destination.size(),
                    timeout.count());
}

inline void lindex(Connection &connection, const StringView &key, long long index) {
    connection.send("LINDEX %b %lld",
                    key.data(), key.size(),
                    index);
}

void linsert(Connection &connection,
                const StringView &key,
                InsertPosition position,
                const StringView &pivot,
                const StringView &val);

inline void llen(Connection &connection,
                    const StringView &key) {
    connection.send("LLEN %b", key.data(), key.size());
}

inline void lpop(Connection &connection, const StringView &key) {
    connection.send("LPOP %b",
                    key.data(), key.size());
}

inline void lpush(Connection &connection, const StringView &key, const StringView &val) {
    connection.send("LPUSH %b %b",
                    key.data(), key.size(),
                    val.data(), val.size());
}

template <typename Iter>
inline void lpush_range(Connection &connection,
                        const StringView &key,
                        Iter first,
                        Iter last) {
    Connection::CmdArgs args;
    args << "LPUSH" << key << std::make_pair(first, last);

    connection.send(args);
}

inline void lpushx(Connection &connection, const StringView &key, const StringView &val) {
    connection.send("LPUSHX %b %b",
                    key.data(), key.size(),
                    val.data(), val.size());
}

inline void lrange(Connection &connection,
                    const StringView &key,
                    long long start,
                    long long stop) {
    connection.send("LRANGE %b %lld %lld",
                    key.data(), key.size(),
                    start,
                    stop);
}

inline void lrem(Connection &connection,
                    const StringView &key,
                    long long count,
                    const StringView &val) {
    connection.send("LREM %b %lld %b",
                    key.data(), key.size(),
                    count,
                    val.data(), val.size());
}

inline void lset(Connection &connection,
                    const StringView &key,
                    long long index,
                    const StringView &val) {
    connection.send("LSET %b %lld %b",
                    key.data(), key.size(),
                    index,
                    val.data(), val.size());
}

inline void ltrim(Connection &connection,
                    const StringView &key,
                    long long start,
                    long long stop) {
    connection.send("LTRIM %b %lld %lld",
                    key.data(), key.size(),
                    start,
                    stop);
}

inline void rpop(Connection &connection, const StringView &key) {
    connection.send("RPOP %b", key.data(), key.size());
}

inline void rpoplpush(Connection &connection,
                        const StringView &source,
                        const StringView &destination) {
    connection.send("RPOPLPUSH %b %b",
                    source.data(), source.size(),
                    destination.data(), destination.size());
}

inline void rpush(Connection &connection, const StringView &key, const StringView &val) {
    connection.send("RPUSH %b %b",
                    key.data(), key.size(),
                    val.data(), val.size());
}

template <typename Iter>
inline void rpush_range(Connection &connection,
                        const StringView &key,
                        Iter first,
                        Iter last) {
    Connection::CmdArgs args;
    args << "RPUSH" << key << std::make_pair(first, last);

    connection.send(args);
}

inline void rpushx(Connection &connection, const StringView &key, const StringView &val) {
    connection.send("RPUSHX %b %b",
                    key.data(), key.size(),
                    val.data(), val.size());
}

// HASH commands.

inline void hdel(Connection &connection, const StringView &key, const StringView &field) {
    connection.send("HDEL %b %b",
                    key.data(), key.size(),
                    field.data(), field.size());
}

template <typename Iter>
inline void hdel_range(Connection &connection,
                        const StringView &key,
                        Iter first,
                        Iter last) {
    Connection::CmdArgs args;
    args << "HDEL" << key << std::make_pair(first, last);

    connection.send(args);
}

inline void hexists(Connection &connection, const StringView &key, const StringView &field) {
    connection.send("HEXISTS %b %b",
                    key.data(), key.size(),
                    field.data(), field.size());
}

inline void hget(Connection &connection, const StringView &key, const StringView &field) {
    connection.send("HGET %b %b",
                    key.data(), key.size(),
                    field.data(), field.size());
}

inline void hgetall(Connection &connection, const StringView &key) {
    connection.send("HGETALL %b", key.data(), key.size());
}

inline void hincrby(Connection &connection,
                    const StringView &key,
                    const StringView &field,
                    long long increment) {
    connection.send("HINCRBY %b %b %lld",
                    key.data(), key.size(),
                    field.data(), field.size(),
                    increment);
}

inline void hincrbyfloat(Connection &connection,
                            const StringView &key,
                            const StringView &field,
                            double increment) {
    connection.send("HINCRBYFLOAT %b %b %f",
                    key.data(), key.size(),
                    field.data(), field.size(),
                    increment);
}

inline void hkeys(Connection &connection, const StringView &key) {
    connection.send("HKEYS %b", key.data(), key.size());
}

inline void hlen(Connection &connection, const StringView &key) {
    connection.send("HLEN %b", key.data(), key.size());
}

template <typename Iter>
inline void hmget(Connection &connection,
                    const StringView &key,
                    Iter first,
                    Iter last) {
    Connection::CmdArgs args;
    args << "HMGET" << key << std::make_pair(first, last);

    connection.send(args);
}

template <typename Iter>
inline void hmset(Connection &connection,
                    const StringView &key,
                    Iter first,
                    Iter last) {
    Connection::CmdArgs args;
    args << "HMSET" << key << std::make_pair(first, last);

    connection.send(args);
}

inline void hset(Connection &connection,
                    const StringView &key,
                    const StringView &field,
                    const StringView &val) {
    connection.send("HSET %b %b %b",
                    key.data(), key.size(),
                    field.data(), field.size(),
                    val.data(), val.size());
}

inline void hsetnx(Connection &connection,
                    const StringView &key,
                    const StringView &field,
                    const StringView &val) {
    connection.send("HSETNX %b %b %b",
                    key.data(), key.size(),
                    field.data(), field.size(),
                    val.data(), val.size());
}

inline void hstrlen(Connection &connection,
                    const StringView &key,
                    const StringView &field) {
    connection.send("HSTRLEN %b %b",
                    key.data(), key.size(),
                    field.data(), field.size());
}

inline void hvals(Connection &connection, const StringView &key) {
    connection.send("HVALS %b", key.data(), key.size());
}

// SET commands

inline void sadd(Connection &connection,
                    const StringView &key,
                    const StringView &member) {
    connection.send("SADD %b %b",
                    key.data(), key.size(),
                    member.data(), member.size());
}

template <typename Iter>
inline void sadd_range(Connection &connection,
                        const StringView &key,
                        Iter first,
                        Iter last) {
    Connection::CmdArgs args;
    args << "SADD" << key << std::make_pair(first, last);

    connection.send(args);
}

inline void scard(Connection &connection, const StringView &key) {
    connection.send("SCARD %b", key.data(), key.size());
}

template <typename Input>
inline void sdiff(Connection &connection, Input first, Input last) {
    Connection::CmdArgs args;
    args << "SDIFF" << std::make_pair(first, last);

    connection.send(args);
}

template <typename Input>
inline void sdiffstore(Connection &connection,
                        const StringView &destination,
                        Input first,
                        Input last) {
    Connection::CmdArgs args;
    args << "SDIFFSTORE" << destination << std::make_pair(first, last);

    connection.send(args);
}

template <typename Input>
inline void sinter(Connection &connection, Input first, Input last) {
    Connection::CmdArgs args;
    args << "SINTER" << std::make_pair(first, last);

    connection.send(args);
}

template <typename Input>
inline void sinterstore(Connection &connection,
                        const StringView &destination,
                        Input first,
                        Input last) {
    Connection::CmdArgs args;
    args << "SINTERSTORE" << destination << std::make_pair(first, last);

    connection.send(args);
}

inline void sismember(Connection &connection,
                        const StringView &key,
                        const StringView &member) {
    connection.send("SISMEMBER %b %b",
                    key.data(), key.size(),
                    member.data(), member.size());
}

inline void smembers(Connection &connection, const StringView &key) {
    connection.send("SMEMBERS %b", key.data(), key.size());
}

inline void smove(Connection &connection,
                    const StringView &source,
                    const StringView &destination,
                    const StringView &member) {
    connection.send("SMOVE %b %b %b",
                    source.data(), source.size(),
                    destination.data(), destination.size(),
                    member.data(), member.size());
}

inline void spop(Connection &connection, const StringView &key) {
    connection.send("SPOP %b", key.data(), key.size());
}

inline void spop_range(Connection &connection, const StringView &key, long long count) {
    connection.send("SPOP %b %lld",
                    key.data(), key.size(),
                    count);
}

inline void srandmember(Connection &connection, const StringView &key) {
    connection.send("SRANDMEMBER %b", key.data(), key.size());
}

inline void srandmember_range(Connection &connection,
                                const StringView &key,
                                long long count) {
    connection.send("SRANDMEMBER %b %lld",
                    key.data(), key.size(),
                    count);
}

inline void srem(Connection &connection,
                    const StringView &key,
                    const StringView &member) {
    connection.send("SREM %b %b",
                    key.data(), key.size(),
                    member.data(), member.size());
}

template <typename Iter>
inline void srem_range(Connection &connection,
                    const StringView &key,
                    Iter first,
                    Iter last) {
    Connection::CmdArgs args;
    args << "SREM" << key << std::make_pair(first, last);

    connection.send(args);
}

template <typename Input>
inline void sunion(Connection &connection, Input first, Input last) {
    Connection::CmdArgs args;
    args << "SUNION" << std::make_pair(first, last);

    connection.send(args);
}

template <typename Input>
inline void sunionstore(Connection &connection,
                        const StringView &destination,
                        Input first,
                        Input last) {
    Connection::CmdArgs args;
    args << "SUNIONSTORE" << destination << std::make_pair(first, last);

    connection.send(args);
}

// Sorted Set commands.

template <typename Iter>
void zadd_range(Connection &connection,
                const StringView &key,
                Iter first,
                Iter last,
                bool changed,
                UpdateType type);

inline void zadd(Connection &connection,
                    const StringView &key,
                    double score,
                    const StringView &member,
                    bool changed,
                    UpdateType type) {
    auto tmp = {std::make_pair(score, member)};

    zadd_range(connection, key, tmp.begin(), tmp.end(), changed, type);
}

inline void zcard(Connection &connection, const StringView &key) {
    connection.send("ZCARD %b", key.data(), key.size());
}

template <typename Interval>
inline void zcount(Connection &connection,
                    const StringView &key,
                    const Interval &interval) {
    connection.send("ZCOUNT %b %s %s",
                    key.data(), key.size(),
                    interval.min().c_str(),
                    interval.max().c_str());
}

inline void zincrby(Connection &connection,
                    const StringView &key,
                    double increment,
                    const StringView &member) {
    connection.send("ZINCRBY %b %f %b",
                    key.data(), key.size(),
                    increment,
                    member.data(), member.size());
}

template <typename Input>
void zinterstore(Connection &connection,
                    const StringView &destination,
                    Input first,
                    Input last,
                    Aggregation aggr);

template <typename Input>
void zunionstore(Connection &connection,
                    const StringView &destination,
                    Input first,
                    Input last,
                    Aggregation aggr);

template <typename Interval>
inline void zlexcount(Connection &connection,
                        const StringView &key,
                        const Interval &interval) {
    const auto &min = interval.min();
    const auto &max = interval.max();

    connection.send("ZLEXCOUNT %b %b %b",
                    key.data(), key.size(),
                    min.data(), min.size(),
                    max.data(), max.size());
}

template <typename Output>
void zrange(Connection &connection,
                const StringView &key,
                long long start,
                long long stop);

template <typename Interval>
inline void zrangebylex(Connection &connection,
                        const StringView &key,
                        const Interval &interval,
                        const LimitOptions &opts) {
    const auto &min = interval.min();
    const auto &max = interval.max();

    connection.send("ZRANGEBYLEX %b %b %b LIMIT %lld %lld",
                    key.data(), key.size(),
                    min.data(), min.size(),
                    max.data(), max.size(),
                    opts.offset,
                    opts.count);
}

template <typename Interval, typename Output>
void zrangebyscore(Connection &connection,
                    const StringView &key,
                    const Interval &interval,
                    const LimitOptions &opts);

inline void zrank(Connection &connection,
                    const StringView &key,
                    const StringView &member) {
    connection.send("ZRANK %b %b",
                    key.data(), key.size(),
                    member.data(), member.size());
}

inline void zrem(Connection &connection,
                    const StringView &key,
                    const StringView &member) {
    connection.send("ZREM %b %b",
                    key.data(), key.size(),
                    member.data(), member.size());
}

template <typename Input>
inline void zrem_range(Connection &connection,
                        const StringView &key,
                        Input first,
                        Input last) {
    Connection::CmdArgs args;
    args << "ZREM" << key << std::make_pair(first, last);

    connection.send(args);
}

template <typename Interval>
inline void zremrangebylex(Connection &connection,
                            const StringView &key,
                            const Interval &interval) {
    const auto &min = interval.min();
    const auto &max = interval.max();

    connection.send("ZREMRANGEBYLEX %b %b %b",
                    key.data(), key.size(),
                    min.data(), min.size(),
                    max.data(), max.size());
}

inline void zremrangebyrank(Connection &connection,
                            const StringView &key,
                            long long start,
                            long long stop) {
    connection.send("zremrangebyrank %b %lld %lld",
                    key.data(), key.size(),
                    start,
                    stop);
}

template <typename Interval>
inline void zremrangebyscore(Connection &connection,
                                const StringView &key,
                                const Interval &interval) {
    const auto &min = interval.min();
    const auto &max = interval.max();

    connection.send("ZREMRANGEBYSCORE %b %b %b",
                    key.data(), key.size(),
                    min.data(), min.size(),
                    max.data(), max.size());
}

template <typename Outupt>
void zrevrange(Connection &connection,
                const StringView &key,
                long long start,
                long long stop);

template <typename Interval>
inline void zrevrangebylex(Connection &connection,
                            const StringView &key,
                            const Interval &interval,
                            const LimitOptions &opts) {
    const auto &min = interval.min();
    const auto &max = interval.max();

    connection.send("ZREVRANGEBYLEX %b %b %b LIMIT %lld %lld",
                    key.data(), key.size(),
                    max.data(), max.size(),
                    min.data(), min.size(),
                    opts.offset,
                    opts.count);
}

template <typename Interval, typename Output>
void zrevrangebyscore(Connection &connection,
                        const StringView &key,
                        const Interval &interval,
                        const LimitOptions &opts);

inline void zrevrank(Connection &connection,
                        const StringView &key,
                        const StringView &member) {
    connection.send("ZREVRANK %b %b",
                    key.data(), key.size(),
                    member.data(), member.size());
}

inline void zscore(Connection &connection,
                    const StringView &key,
                    const StringView &member) {
    connection.send("ZSCORE %b %b",
                    key.data(), key.size(),
                    member.data(), member.size());
}

// HYPERLOGLOG commands.

inline void pfadd(Connection &connection,
                    const StringView &key,
                    const StringView &element) {
    connection.send("PFADD %b %b",
                    key.data(), key.size(),
                    element.data(), element.size());
}

template <typename Input>
inline void pfadd_range(Connection &connection,
                        const StringView &key,
                        Input first,
                        Input last) {
    Connection::CmdArgs args;
    args << "PFADD" << key << std::make_pair(first, last);

    connection.send(args);
}

inline void pfcount(Connection &connection, const StringView &key) {
    connection.send("PFCOUNT %b", key.data(), key.size());
}

template <typename Input>
inline void pfcount_range(Connection &connection,
                            Input first,
                            Input last) {
    Connection::CmdArgs args;
    args << "PFCOUNT" << std::make_pair(first, last);

    connection.send(args);
}

template <typename Input>
inline void pfmerge(Connection &connection,
                    const StringView &destination,
                    Input first,
                    Input last) {
    Connection::CmdArgs args;
    args << "PFMERGE" << destination << std::make_pair(first, last);

    connection.send(args);
}

namespace detail {

void set_update_type(Connection::CmdArgs &args, UpdateType type);

template <typename Cmd, typename ...Args>
inline void score_command(std::true_type, Cmd cmd, Args &&... args) {
    cmd(std::forward<Args>(args)..., true);
}

template <typename Cmd, typename ...Args>
inline void score_command(std::false_type, Cmd cmd, Args &&... args) {
    cmd(std::forward<Args>(args)..., false);
}

template <typename Output, typename Cmd, typename ...Args>
inline void score_command(Cmd cmd, Args &&... args) {
    score_command(typename IsKvPairIter<Output>::type(), cmd, std::forward<Args>(args)...);
}

inline void zrange(Connection &connection,
                const StringView &key,
                long long start,
                long long stop,
                bool with_scores) {
    if (with_scores) {
        connection.send("ZRANGE %b %lld %lld WITHSCORES",
                        key.data(), key.size(),
                        start,
                        stop);
    } else {
        connection.send("ZRANGE %b %lld %lld",
                        key.data(), key.size(),
                        start,
                        stop);
    }
}

template <typename Interval>
void zrangebyscore(Connection &connection,
                    const StringView &key,
                    const Interval &interval,
                    const LimitOptions &opts,
                    bool with_scores) {
    const auto &min = interval.min();
    const auto &max = interval.max();

    if (with_scores) {
        connection.send("ZRANGEBYSCORE %b %b %b WITHSCORES LIMIT %lld %lld",
                        key.data(), key.size(),
                        min.data(), min.size(),
                        max.data(), max.size(),
                        opts.offset,
                        opts.count);
    } else {
        connection.send("ZRANGEBYSCORE %b %b %b LIMIT %lld %lld",
                        key.data(), key.size(),
                        min.data(), min.size(),
                        max.data(), max.size(),
                        opts.offset,
                        opts.count);
    }
}

inline void zrevrange(Connection &connection,
                        const StringView &key,
                        long long start,
                        long long stop,
                        bool with_scores) {
    if (with_scores) {
        connection.send("ZREVRANGE %b %lld %lld WITHSCORES",
                        key.data(), key.size(),
                        start,
                        stop);
    } else {
        connection.send("ZREVRANGE %b %lld %lld",
                        key.data(), key.size(),
                        start,
                        stop);
    }
}

template <typename Interval>
inline void zrevrangebyscore(Connection &connection,
                                const StringView &key,
                                const Interval &interval,
                                const LimitOptions &opts,
                                bool with_scores) {
    const auto &min = interval.min();
    const auto &max = interval.max();

    if (with_scores) {
        connection.send("ZREVRANGEBYSCORE %b %b %b WITHSCORES LIMIT %lld %lld",
                        key.data(), key.size(),
                        max.data(), max.size(),
                        min.data(), min.size(),
                        opts.offset,
                        opts.count);
    } else {
        connection.send("ZREVRANGEBYSCORE %b %b %b LIMIT %lld %lld",
                        key.data(), key.size(),
                        max.data(), max.size(),
                        min.data(), min.size(),
                        opts.offset,
                        opts.count);
    }
}

void set_aggregation_type(Connection::CmdArgs &args, Aggregation type);

template <typename Input>
void zinterstore(std::false_type,
                    Connection &connection,
                    const StringView &destination,
                    Input first,
                    Input last,
                    Aggregation aggr) {
    Connection::CmdArgs args;
    args << "ZINTERSTORE" << destination << std::distance(first, last)
        << std::make_pair(first, last);

    set_aggregation_type(args, aggr);

    connection.send(args);
}

template <typename Input>
void zinterstore(std::true_type,
                    Connection &connection,
                    const StringView &destination,
                    Input first,
                    Input last,
                    Aggregation aggr) {
    Connection::CmdArgs args;
    args << "ZINTERSTORE" << destination << std::distance(first, last);

    for (auto iter = first; iter != last; ++iter) {
        args << iter->first;
    }

    args << "WEIGHTS";

    for (auto iter = first; iter != last; ++iter) {
        args << iter->second;
    }

    set_aggregation_type(args, aggr);

    connection.send(args);
}

template <typename Input>
void zunionstore(std::false_type,
                    Connection &connection,
                    const StringView &destination,
                    Input first,
                    Input last,
                    Aggregation aggr) {
    Connection::CmdArgs args;
    args << "ZUNIONSTORE" << destination << std::distance(first, last)
        << std::make_pair(first, last);

    set_aggregation_type(args, aggr);

    connection.send(args);
}

template <typename Input>
void zunionstore(std::true_type,
                    Connection &connection,
                    const StringView &destination,
                    Input first,
                    Input last,
                    Aggregation aggr) {
    Connection::CmdArgs args;
    args << "ZUNIONSTORE" << destination << std::distance(first, last);

    for (auto iter = first; iter != last; ++iter) {
        args << iter->first;
    }

    args << "WEIGHTS";

    for (auto iter = first; iter != last; ++iter) {
        args << iter->second;
    }

    set_aggregation_type(args, aggr);

    connection.send(args);
}

}

}

}

}

namespace sw {

namespace redis {

namespace cmd {

template <typename Input>
void bitop(Connection &connection,
            BitOp op,
            const StringView &destination,
            Input first,
            Input last) {
    Connection::CmdArgs args;
    args << "BITOP";
    switch (op) {
    case BitOp::AND:
        args << "AND";
        break;

    case BitOp::OR:
        args << "OR";
        break;

    case BitOp::XOR:
        args << "XOR";
        break;

    case BitOp::NOT:
        args << "NOT";
        break;

    default:
        throw RException("Unknown bit operations");
    }

    args << destination << std::make_pair(first, last);

    connection.send(args);
}

template <typename Iter>
void zadd_range(Connection &connection,
                const StringView &key,
                Iter first,
                Iter last,
                bool changed,
                UpdateType type) {
    Connection::CmdArgs args;

    args << "ZADD" << key;

    detail::set_update_type(args, type);

    if (changed) {
        args << "CH";
    }

    args << std::make_pair(first, last);

    connection.send(args);
}

template <typename Output>
inline void zrange(Connection &connection,
                const StringView &key,
                long long start,
                long long stop) {
    detail::score_command<Output>(detail::zrange, connection, key, start, stop);
}

template <typename Interval, typename Output>
void zrangebyscore(Connection &connection,
                    const StringView &key,
                    const Interval &interval,
                    const LimitOptions &opts) {
    detail::score_command<Output>(detail::zrangebyscore<Interval>, connection, key, interval, opts);
}

template <typename Output>
void zrevrange(Connection &connection,
                const StringView &key,
                long long start,
                long long stop) {
    detail::score_command<Output>(detail::zrevrange, connection, key, start, stop);
}

template <typename Interval, typename Output>
void zrevrangebyscore(Connection &connection,
                        const StringView &key,
                        const Interval &interval,
                        const LimitOptions &opts) {
    detail::score_command<Output>(detail::zrevrangebyscore<Interval>,
                                    connection,
                                    key,
                                    interval,
                                    opts);
}

template <typename Input>
void zinterstore(Connection &connection,
                    const StringView &destination,
                    Input first,
                    Input last,
                    Aggregation aggr) {
    detail::zinterstore(typename IsKvPairIter<Input>::type(),
                        connection,
                        destination,
                        first,
                        last,
                        aggr);
}

template <typename Input>
void zunionstore(Connection &connection,
                    const StringView &destination,
                    Input first,
                    Input last,
                    Aggregation aggr) {
    detail::zunionstore(typename IsKvPairIter<Input>::type(),
                        connection,
                        destination,
                        first,
                        last,
                        aggr);
}

}

}

}

#endif // end SEWENEW_REDISPLUSPLUS_COMMAND_H