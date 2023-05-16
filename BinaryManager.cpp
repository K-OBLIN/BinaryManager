#include "BinaryManager.hpp"

/**
 * @brief Constructor
 * 
 * @param buffer Data
 */
BinaryReader::BinaryReader(const std::span<char>& buffer) noexcept : m_span(buffer), m_position(0) {
    
}

/**
 * @brief Constructor
 * 
 * @param filePath The file path
 */
BinaryReader::BinaryReader(const std::string filePath) {
    std::ifstream ifs { filePath, std::ifstream::binary | std::ifstream::in };
    if (ifs.fail()) {
        throw std::ios_base::failure("Failed to open file!");
    }

    auto size = std::filesystem::file_size(filePath);
    std::vector<char> buf(size);
    ifs.read(buf.data(), size);

    m_span = buf;
    m_position = 0;
}

/**
 * @brief Set the buffer(data)
 * 
 * @param buffer Data
 */
void BinaryReader::SetBuffer(const std::span<char>& buffer) noexcept {
    m_span = buffer;
}

/**
 * @brief Get the buffer(data)
 * 
 * @return std::span<char>
 */
std::span<char> BinaryReader::GetBuffer() const noexcept {
    return m_span;
}

/**
 * @brief Get the buffer as std::vector
 * 
 * @return std::vector<char> 
 */
std::vector<char> BinaryReader::GetVectorBuffer() const noexcept {
    return std::vector<char>(m_span.begin(), m_span.end());
}

/**
 * @brief Set the position
 * 
 * @param pos The position(offset)
 */
void BinaryReader::SetPosition(const std::size_t pos) noexcept {
    m_position = pos;
}

/**
 * @brief Get the position
 * 
 * @return std::size_t 
 */
std::size_t BinaryReader::GetPosition() const noexcept {
    return m_position;
}

/**
 * @brief Get the length(size)
 * 
 * @return std::size_t 
 */
std::size_t BinaryReader::GetLength() const noexcept {
    return m_span.size();
}

/**
 * @brief Read the byte
 * 
 * @return std::uint8_t 
 */
std::uint8_t BinaryReader::ReadByte() {
    if (m_position + sizeof(std::uint8_t) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    std::uint8_t buf = static_cast<std::uint8_t>(m_span[m_position]);
    m_position += sizeof(std::uint8_t);

    return buf;
}

/**
 * @brief Read the 2Bytes
 * 
 * @return std::int16_t 
 */
std::int16_t BinaryReader::ReadInt16() {
    if (m_position + sizeof(std::int16_t) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    std::int16_t buf = static_cast<std::int16_t>(m_span[m_position]) | static_cast<std::int16_t>(m_span[m_position + 1]) << 8;
    m_position += sizeof(std::int16_t);

    return buf;
}

/**
 * @brief Read the 4Bytes
 * 
 * @return std::int32_t 
 */
std::int32_t BinaryReader::ReadInt32() {
    if (m_position + sizeof(std::int32_t) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    std::int32_t buf = static_cast<std::int32_t>(m_span[m_position]) | static_cast<std::int32_t>(m_span[m_position + 1]) << 8 | static_cast<std::int32_t>(m_span[m_position + 2]) << 16 | static_cast<std::int32_t>(m_span[m_position + 3]) << 24;
    m_position += sizeof(std::int32_t);

    return buf;
}

/**
 * @brief Read the 8Bytes
 * 
 * @return std::int64_t 
 */
std::int64_t BinaryReader::ReadInt64() {
    if (m_position + sizeof(std::int64_t) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    std::int64_t buf = static_cast<std::int64_t>(m_span[m_position]) | static_cast<std::int64_t>(m_span[m_position + 1]) << 8 | static_cast<std::int64_t>(m_span[m_position + 2]) << 16 | static_cast<std::int64_t>(m_span[m_position + 3]) << 24 | static_cast<std::int64_t>(m_span[m_position + 4]) << 32 | static_cast<std::int64_t>(m_span[m_position + 5]) << 40 | static_cast<std::int64_t>(m_span[m_position + 6]) << 48 | static_cast<std::int64_t>(m_span[m_position + 7]) << 56;
    m_position += sizeof(std::int64_t);

    return buf;
}

/**
 * @brief Read the 2Bytes
 * 
 * @return std::uint16_t 
 */
std::uint16_t BinaryReader::ReadUInt16() {
    if (m_position + sizeof(std::uint16_t) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    std::uint16_t buf = static_cast<std::uint16_t>(m_span[m_position]) | static_cast<std::uint16_t>(m_span[m_position + 1]) << 8;
    m_position += sizeof(std::uint16_t);

    return buf;
}

/**
 * @brief Read the 4Bytes
 * 
 * @return std::uint32_t 
 */
std::uint32_t BinaryReader::ReadUInt32() {
    if (m_position + sizeof(std::uint32_t) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    std::uint32_t buf = static_cast<std::uint32_t>(m_span[m_position]) | static_cast<std::uint32_t>(m_span[m_position + 1]) << 8 | static_cast<std::uint32_t>(m_span[m_position + 2]) << 16 | static_cast<std::uint32_t>(m_span[m_position + 3]) << 24;
    m_position += sizeof(std::uint32_t);

    return buf;
}

/**
 * @brief Read the 8Bytes
 * 
 * @return std::uint64_t 
 */
std::uint64_t BinaryReader::ReadUInt64() {
    if (m_position + sizeof(std::uint64_t) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    std::uint64_t buf = static_cast<std::uint64_t>(m_span[m_position]) | static_cast<std::uint64_t>(m_span[m_position + 1]) << 8 | static_cast<std::uint64_t>(m_span[m_position + 2]) << 16 | static_cast<std::uint64_t>(m_span[m_position + 3]) << 24 | static_cast<std::uint64_t>(m_span[m_position + 4]) << 32 | static_cast<std::uint64_t>(m_span[m_position + 5]) << 40 | static_cast<std::uint64_t>(m_span[m_position + 6]) << 48 | static_cast<std::uint64_t>(m_span[m_position + 7]) << 56;
    m_position += sizeof(std::uint64_t);

    return buf;
}

/**
 * @brief Read the boolean
 * 
 * @return true 
 * @return false 
 */
bool BinaryReader::ReadBoolean() {
    return static_cast<bool>(ReadByte());
}

/**
 * @brief Read the character
 * 
 * @return char 
 */
char BinaryReader::ReadChar() {
    return static_cast<char>(ReadByte());
}

/**
 * @brief Read the char array
 * 
 * @param bytes Number of char
 * @return std::vector<char> 
 */
std::vector<char> BinaryReader::ReadChars(const std::size_t bytes) {
    if (m_position + bytes > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    std::vector<char> vec;
    vec.reserve(bytes);

    for (auto i = 0; i < bytes; ++i) {
        vec.push_back(m_span[m_position + i]);
    }

    m_position += bytes;

    return vec;
}

/**
 * @brief Read the string
 * 
 * @return std::string 
 */
std::string BinaryReader::ReadString() {
    auto start = m_span.subspan(m_position).data();
    auto end = start + m_span.subspan(m_position).size();
    auto null_pos = std::find(start, end, '\0');
    if (null_pos == end) { 
        throw std::out_of_range("End of span reached before null terminator!");   
    }

    auto buf = std::string(start, null_pos);
    m_position += (buf.length() + 1); // + null

    return buf;
}

/**
 * @brief Read the float number(4Bytes)
 * 
 * @return float 
 */
float BinaryReader::ReadSingle() {
    if (m_position + sizeof(float) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    auto buf = 0.0F;
    std::memcpy(&buf, m_span.data() + m_position, sizeof(float));
    m_position += sizeof(float);

    return buf;
}

/**
 * @brief Read the double number(8Bytes)
 * 
 * @return double 
 */
double BinaryReader::ReadDouble() {
    if (m_position + sizeof(double) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    auto buf = 0.0;
    std::memcpy(&buf, m_span.data() + m_position, sizeof(double));
    m_position += sizeof(double);

    return buf;
}

/**
 * @brief Read the long double number(8Bytes+)
 * 
 * @return long double 
 * @warning Different platforms have difference sizes.
 */
long double BinaryReader::ReadDecimal() {
    if (m_position + sizeof(long double) > m_span.size()) {
        throw std::out_of_range("Out of Range!");
    }

    auto buf = 0.0L;
    std::memcpy(&buf, m_span.data() + m_position, sizeof(long double));
    m_position += sizeof(long double);

    return buf;
}

/**
 * @brief Constructor
 * 
 * @param filePath The file path
 */
BinaryWriter::BinaryWriter(const std::string filePath) {
    m_ofs = std::ofstream { filePath, std::ofstream::binary | std::ofstream::out };
    if (m_ofs.fail()) {
        throw std::ios_base::failure("Failed to open file!");
    }
}

/**
 * @brief Destructor
 * 
 */
BinaryWriter::~BinaryWriter() {
    if (!m_ofs.fail()) {
        m_ofs.close();
    }
}

/**
 * @brief Set the position
 * 
 * @param pos The position(offset)
 */
void BinaryWriter::SetPosition(const std::size_t pos) noexcept {
    m_ofs.seekp(pos);
}

/**
 * @brief Get the position
 * 
 * @return std::size_t 
 */
std::size_t BinaryWriter::GetPosition() noexcept {
    return static_cast<std::size_t>(m_ofs.tellp());
}

/**
 * @brief Get the length(size)
 * 
 * @return std::size_t 
 */
std::size_t BinaryWriter::GetLength() noexcept {
    m_ofs.seekp(0, std::ios::end);
    auto length = static_cast<std::size_t>(m_ofs.tellp());
    m_ofs.seekp(0, std::ios::beg);

    return length;
}

/**
 * @brief Write the byte
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::int8_t value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the 2Bytes
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::int16_t value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the 4Bytes
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::int32_t value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the 8Bytes
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::int64_t value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));    
}

/**
 * @brief Write the byte
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::uint8_t value) {    
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the 2Bytes
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::uint16_t value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the 4Bytes
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::uint32_t value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the 8Bytes
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::uint64_t value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the boolean
 * 
 * @param value 
 */
void BinaryWriter::Write(const bool value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the character
 * 
 * @param value 
 */
void BinaryWriter::Write(const char value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the buffer(data)
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::span<char>& value) {    
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)value.data(), value.size());
}

/**
 * @brief Write the string
 * 
 * @param value 
 */
void BinaryWriter::Write(const std::string value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);
    
    m_ofs.write(value.c_str(), value.size());
}

/**
 * @brief Write the float number(4Bytes)
 * 
 * @param value 
 */
void BinaryWriter::Write(const float value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the double number(8Bytes)
 * 
 * @param value 
 */
void BinaryWriter::Write(const double value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}

/**
 * @brief Write the long double number(8Bytes+)
 * 
 * @param value 
 * @warning Different platforms have different sizes.
 */
void BinaryWriter::Write(const long double value) {
    auto currentPos = GetPosition();

    if (currentPos > GetLength()) {
        throw std::ios_base::failure("End of file!");
    }
    SetPosition(currentPos);

    m_ofs.write((const char*)&value, sizeof(value));
}