##################################################
## Project
##################################################
include(${CMAKETOOLS_DIR}/External/Check.cmake)

##################################################
## Check
##################################################

# Check if built file exists
if(NOT EXISTS ${CMAKETOOLS_CURRENT_BUILT_FILE})
	# Download prebuilt package from the repository
	set(md5sum "")
	if(WIN32)
		if(CMAKETOOLS_TARGET_BITSIZE MATCHES "64")
			# md5sum of the 64bit Windows package
			set(md5sum "19c3766a9b2ba67f0932b3a5edae95ac")
		else()
			# md5sum of the 32bit Windows package
			set(md5sum "ac1c767baf21319d85e0a6265b8672e5")
		endif()
	elseif(ANDROID)
		# [TODO] Checksum for "armeabi" & "armeabi-v7a"
	elseif(LINUX)
		if(CMAKETOOLS_TARGET_BITSIZE MATCHES "64")
			# md5sum of the 64bit Linux package
			set(md5sum "22b9f7a7b4d841a6032ec27c7a664372")
		else()
			# md5sum of the 32bit Linux package
			set(md5sum "2677caee740d091edd049f6bfbe641b5")
		endif()
	endif()
	external_check_download("" ${md5sum})

	# Unpack the package
	external_check_unpack()
endif()

# Done
external_check_done()