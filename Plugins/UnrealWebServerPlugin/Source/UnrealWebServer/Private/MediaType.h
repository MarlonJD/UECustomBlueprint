// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

/**
* The EMediaType enum stores the most common mime types
* This enum is needed to fulfill The UResponse with SetResponseContentType method
* @author Isara Technologies.
* @version 1.0
*/
UENUM(BlueprintType)
enum class EMediaType : uint8
{
	APPLICATION_JAVASCRIPT,
	APPLICATION_JSON,
	APPLICATION_OCTET_STREAM,
	APPLICATION_OGG,
	APPLICATION_PDF,
	APPLICATION_ZIP,
	AUDIO_MPEG,
	AUDIO_WAV,
	IMAGE_GIF,
	IMAGE_JPEG,
	IMAGE_PNG,
	IMAGE_TIFF,
	MULTIPART_FORM_DATA,
	TEXT_CSS,
	TEXT_CSV,
	TEXT_HTML,
	TEXT_JAVASCRIPT,
	TEXT_PLAIN,
	TEXT_XML,
	VIDEO_MP4,
	VIDEO_MPEG,
	VIDEO_QUICKTIME,
	VIDEO_WEBM
};

FString MediaTypeToString(const EMediaType MediaType);