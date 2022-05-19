#增加cmake 工程子目录
#add_subdirectory(queue)

include_directories(
	../soc_sdk/include
	qanthink
	qanthink/libffmpeg/include
)

link_directories(
	../soc_sdk/dynamic
	qanthink
	qanthink/libffmpeg/lib
)

#增加需要编译的源文件
aux_source_directory(. DIR_SRC)

#编译出可执行文件
add_executable(skyipc ${DIR_SRC}) # 生成可执行文件

#设置 target 需要链接的库
target_link_libraries(skyipc 
	mi_ao
	mi_sys
	cam_os_wrapper

	pthread
	audio_player
	ffmpeg
	ao
	avformat avcodec swresample avutil
)

#strip 剪裁
add_custom_target(stripTask
	COMMAND echo ================ make strip task ================
	COMMAND ls -l -h skyipc
	COMMAND ${CMAKE_STRIP} -s skyipc
	COMMAND ls -l -h skyipc
)

