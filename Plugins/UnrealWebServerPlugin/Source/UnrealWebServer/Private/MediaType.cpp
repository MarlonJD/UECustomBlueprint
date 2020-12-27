// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#include "MediaType.h"
#include "UnrealWebServerPrivatePCH.h"

FString MediaTypeToString(const EMediaType MediaType)
{
	switch (MediaType) {
	case EMediaType::APPLICATION_JAVASCRIPT:
		return FString("application/javascript");
	case EMediaType::APPLICATION_JSON:
		return FString("application/json");
	case EMediaType::APPLICATION_OCTET_STREAM:
		return FString("application/octet-stream");
	case EMediaType::APPLICATION_OGG:
		return FString("application/ogg");
	case EMediaType::APPLICATION_PDF:
		return FString("application/pdf");
	case EMediaType::APPLICATION_ZIP:
		return FString("application/zip");
	case EMediaType::AUDIO_MPEG:
		return FString("audio/mpeg");
	case EMediaType::AUDIO_WAV:
		return FString("audio/wav");
	case EMediaType::IMAGE_GIF:
		return FString("image/gif");
	case EMediaType::IMAGE_JPEG:
		return FString("image/jpeg");
	case EMediaType::IMAGE_PNG:
		return FString("image/png");
	case EMediaType::IMAGE_TIFF:
		return FString("image/tiff");
	case EMediaType::MULTIPART_FORM_DATA:
		return FString("multipart/form-data");
	case EMediaType::TEXT_CSS:
		return FString("text/css");
	case EMediaType::TEXT_CSV:
		return FString("text/csv");
	case EMediaType::TEXT_HTML:
		return FString("text/html");
	case EMediaType::TEXT_JAVASCRIPT:
		return FString("text/javascript");
	case EMediaType::TEXT_PLAIN:
		return FString("text/plain");
	case EMediaType::TEXT_XML:
		return FString("text/xml");
	case EMediaType::VIDEO_MP4:
		return FString("video/mp4");
	case EMediaType::VIDEO_MPEG:
		return FString("video/mpeg");
	case EMediaType::VIDEO_QUICKTIME:
		return FString("video/quicktime");
	case EMediaType::VIDEO_WEBM:
		return FString("video/webm");
	default:
		return FString("application/octet-stream");
	}
}