/// Copyright © Daniel Adamitskiy. All Rights Reserved.

#pragma once

#include "DA.Type.h"
#include <cstdio>

namespace DA
{
namespace IO 
{

enum class FileAccessMode : int8
{
	Read,
	Write,
	Append,
	ReadUpdate,
	WriteUpdate,
	AppendUpdate,
};

/// Opens a file for a given file access mode.
/// @param fileName - Name of the file with full path to open.
/// @param fileAccessMode - Access mode to open the file with.
/// @return A pointer to the opened file, or nullptr if an error occurred.
DA_INLINE FILE* OpenFile(const char* fileName, FileAccessMode fileAccessMode)
{
	FILE* stream = nullptr;

	switch (fileAccessMode)
	{
	case FileAccessMode::Read:
		{
			fopen_s(&stream, fileName, "r");
		}
		break;
	case FileAccessMode::Write:
		{
			fopen_s(&stream, fileName, "w");
		}
		break;
	case FileAccessMode::Append:
		{
			fopen_s(&stream, fileName, "a");
		}
		break;
	case FileAccessMode::ReadUpdate:
		{
			fopen_s(&stream, fileName, "r+");
		}
		break;
	case FileAccessMode::WriteUpdate:
		{
			fopen_s(&stream, fileName, "w+");
		}
		break;
	case FileAccessMode::AppendUpdate:
		{
			fopen_s(&stream, fileName, "a+");
		}
		break;
	default:
		// We should never enter here.
		break;
	}

	return stream;
}

/// Flushes a given stream.
/// @param streamToFlush - The stream to flush.
/// @return True if the stream was successfully flushed, false otherwise.
DA_FORCEINLINE bool FlushStream(FILE* streamToFlush)
{
	return (fflush(streamToFlush) == 0);
}

/// Writes out a buffer to a given file.
/// @param stream - File to output to.
/// @param buffer - Contents to output to given stream.
/// @return True on successfully outputing to the file, false otherwise.
DA_FORCEINLINE bool WriteBuffer(FILE* stream, const int8* buffer)
{
	return (fputs(buffer, stream) >= 0);
}

/// Closes a given file stream.
/// @param streamToClose - File stream to close.
/// @return True on successfully closing the file, false otherwise.
DA_FORCEINLINE bool CloseFile(FILE* streamToClose)
{
	return (fclose(streamToClose) == 0);
}

/// Removes the specified file.
/// @param fileNameFullPath - File name full path to remove.
/// @return True if the file was successfully removed, false otherwise.
DA_FORCEINLINE bool RemoveFile(const int8* fileNameFullPath)
{
	return (remove(fileNameFullPath) == 0);
}

/// Renames the specified file.
/// @param fileToRenameFullPath - File with full path to rename.
/// @param newFileNameFullPath - Name of the file including full path to rename to.
/// @return True if the file was successfully renamed, false otherwise.
DA_FORCEINLINE bool RenameFile(const int8* fileToRenameFullPath, const int8* newFileNameFullPath)
{
	return (rename(fileToRenameFullPath, newFileNameFullPath) == 0);
}

} // namespace IO
} // namespace DA
