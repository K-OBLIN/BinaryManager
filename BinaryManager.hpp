#pragma once

#include <algorithm>
#include <array>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <string>
#include <span>
#include <vector>

class BinaryReader {
private:
    std::span<char> m_span;
    std::size_t m_position;

public:
    BinaryReader(const std::span<char>& buffer) noexcept;
    BinaryReader(const std::string filePath);

    void SetBuffer(const std::span<char>& buffer) noexcept;
    [[nodiscard]] std::span<char> GetBuffer() const noexcept;
    [[nodiscard]] std::vector<char> GetVectorBuffer() const noexcept;

    void SetPosition(const std::size_t pos) noexcept;
    [[nodiscard]] std::size_t GetPosition() const noexcept;

    [[nodiscard]] std::size_t GetLength() const noexcept;

    [[nodiscard]] std::uint8_t ReadByte();
    [[nodiscard]] std::int16_t ReadInt16();
    [[nodiscard]] std::int32_t ReadInt32();
    [[nodiscard]] std::int64_t ReadInt64();

    [[nodiscard]] std::uint16_t ReadUInt16();
    [[nodiscard]] std::uint32_t ReadUInt32();
    [[nodiscard]] std::uint64_t ReadUInt64();

    [[nodiscard]] bool ReadBoolean();

    [[nodiscard]] char ReadChar();
    [[nodiscard]] std::vector<char> ReadChars(const std::size_t bytes);
    [[nodiscard]] std::string ReadString();

    [[nodiscard]] float ReadSingle();
    [[nodiscard]] double ReadDouble();
    [[nodiscard]] long double ReadDecimal();
};

class BinaryWriter {
private:
    std::ofstream m_ofs;

public:
    BinaryWriter(const std::string filePath);

    void SetPosition(const std::size_t pos) noexcept;
    [[nodiscard]] std::size_t GetPosition() noexcept;

    [[nodiscard]] std::size_t GetLength() noexcept;

    void Write(const std::int8_t value);
    void Write(const std::int16_t value);
    void Write(const std::int32_t value);
    void Write(const std::int64_t value);
    void Write(const std::uint8_t value);
    void Write(const std::uint16_t value);
    void Write(const std::uint32_t value);
    void Write(const std::uint64_t value);
    void Write(const bool value);
    void Write(const char value);
    void Write(const std::span<char>& value);
    void Write(const std::string value);
    void Write(const float value);
    void Write(const double value);
    void Write(const long double value);
};