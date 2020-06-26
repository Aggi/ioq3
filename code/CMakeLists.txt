# ===========================================================================
# Copyright (C) 2020 Aggi

# This file is part of cppioq3 source code.

# cppioq3 source code is free software; you can redistribute it
# and/or modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of the License,
# or (at your option) any later version.

# cppioq3 source code is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with cppioq3 source code; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
# ===========================================================================


cmake_minimum_required(VERSION 3.12)


find_package(SDL2 REQUIRED)
find_package(ZLIB REQUIRED)
find_package(JPEG REQUIRED)

add_library(sys)
target_sources(sys
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code/sys/con_log.c
        ${PROJECT_SOURCE_DIR}/code/sys/con_win32.c
        ${PROJECT_SOURCE_DIR}/code/sys/sys_autoupdater.c
        ${PROJECT_SOURCE_DIR}/code/sys/sys_main.c
        ${PROJECT_SOURCE_DIR}/code/sys/sys_win32.c
)
target_compile_definitions(sys 
    PUBLIC
)
target_link_libraries(sys
    PUBLIC
        SDL2::SDL2
    PRIVATE
        qcommon
)

add_library(asm OBJECT)
target_sources(asm
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code/asm/ftola.asm
        ${PROJECT_SOURCE_DIR}/code/asm/snapvector.asm
        ${PROJECT_SOURCE_DIR}/code/asm/vm_x86_64.asm
)
target_compile_definitions(asm 
    PRIVATE
        idx64
)

add_library(qcommon)
target_sources(qcommon
    PRIVATE


        ${PROJECT_SOURCE_DIR}/code/qcommon/cmd.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/cm_load.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/cm_patch.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/cm_polylib.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/cm_test.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/cm_trace.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/common.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/cvar.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/files.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/huffman.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/ioapi.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/md4.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/md5.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/msg.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/net_chan.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/net_ip.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/puff.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/q_math.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/q_shared.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/unzip.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/vm.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/vm_interpreted.c
        ${PROJECT_SOURCE_DIR}/code/qcommon/vm_x86.c
)
target_compile_definitions(qcommon 
    PUBLIC
        BOTLIB
        STANDALONE
        C_ONLY
)
target_link_libraries(qcommon
    PRIVATE
        ZLIB::ZLIB
        ws2_32
        asm
    PUBLIC
        sys
)

add_library(sdl)
target_sources(sdl
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code/sdl/sdl_gamma.c
        ${PROJECT_SOURCE_DIR}/code/sdl/sdl_glimp.c
        ${PROJECT_SOURCE_DIR}/code/sdl/sdl_input.c
        ${PROJECT_SOURCE_DIR}/code/sdl/sdl_snd.c
)
target_compile_definitions(sdl 
    PUBLIC
)
target_link_libraries(sdl
    PRIVATE
        qcommon
)

add_library(botlib)
target_sources(botlib
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_bspq3.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_cluster.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_debug.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_entity.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_file.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_main.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_move.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_optimize.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_reach.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_route.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_routealt.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_aas_sample.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_ai_char.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_ai_chat.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_ai_gen.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_ai_goal.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_ai_move.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_ai_weap.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_ai_weight.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_ea.c
        ${PROJECT_SOURCE_DIR}/code/botlib/be_interface.c
        ${PROJECT_SOURCE_DIR}/code/botlib/l_crc.c
        ${PROJECT_SOURCE_DIR}/code/botlib/l_libvar.c
        ${PROJECT_SOURCE_DIR}/code/botlib/l_log.c
        ${PROJECT_SOURCE_DIR}/code/botlib/l_memory.c
        ${PROJECT_SOURCE_DIR}/code/botlib/l_precomp.c
        ${PROJECT_SOURCE_DIR}/code/botlib/l_script.c
        ${PROJECT_SOURCE_DIR}/code/botlib/l_struct.c
)
target_compile_definitions(botlib 
    PUBLIC
)
target_link_libraries(botlib
    PRIVATE
        qcommon
)

add_library(servera)
target_sources(servera
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code/server/sv_bot.c
        ${PROJECT_SOURCE_DIR}/code/server/sv_ccmds.c
        ${PROJECT_SOURCE_DIR}/code/server/sv_client.c
        ${PROJECT_SOURCE_DIR}/code/server/sv_game.c
        ${PROJECT_SOURCE_DIR}/code/server/sv_init.c
        ${PROJECT_SOURCE_DIR}/code/server/sv_main.c
        ${PROJECT_SOURCE_DIR}/code/server/sv_net_chan.c
        ${PROJECT_SOURCE_DIR}/code/server/sv_snapshot.c
        ${PROJECT_SOURCE_DIR}/code/server/sv_world.c
)
target_compile_definitions(servera
    PUBLIC
)
target_link_libraries(servera
    PRIVATE
        qcommon
)

add_library(renderercommon)
target_sources(renderercommon
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code/renderercommon/tr_font.c
        ${PROJECT_SOURCE_DIR}/code/renderercommon/tr_image_bmp.c
        ${PROJECT_SOURCE_DIR}/code/renderercommon/tr_image_jpg.c
        ${PROJECT_SOURCE_DIR}/code/renderercommon/tr_image_pcx.c
        ${PROJECT_SOURCE_DIR}/code/renderercommon/tr_image_png.c
        ${PROJECT_SOURCE_DIR}/code/renderercommon/tr_image_tga.c
        ${PROJECT_SOURCE_DIR}/code/renderercommon/tr_noise.c
)
target_compile_definitions(renderercommon 
    PUBLIC
)
target_link_libraries(renderercommon
    PRIVATE
        qcommon
        ${JPEG_LIBRARIES}
)
target_include_directories(renderercommon PRIVATE ${JPEG_INCLUDE_DIR})


add_executable(stringify)
target_sources(stringify
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/stringify.cpp
)
target_compile_definitions(renderercommon 
    PUBLIC
)
target_link_libraries(renderercommon
    PRIVATE
)
target_compile_features(stringify PRIVATE cxx_std_17)

set(glsl_shaders
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/bokeh_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/bokeh_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/calclevels4x_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/calclevels4x_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/depthblur_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/depthblur_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/dlight_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/dlight_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/down4x_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/down4x_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/fogpass_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/fogpass_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/generic_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/generic_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/lightall_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/lightall_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/pshadow_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/pshadow_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/shadowfill_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/shadowfill_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/shadowmask_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/shadowmask_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/ssao_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/ssao_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/texturecolor_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/texturecolor_vp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/tonemap_fp.glsl
    ${PROJECT_SOURCE_DIR}/code/renderergl2/glsl/tonemap_vp.glsl
)

foreach(in_file ${glsl_shaders})
    get_filename_component(basename ${in_file} NAME_WE)
    set(out_file ${PROJECT_BINARY_DIR}/gsls/${basename}.c)
    add_custom_command(
        DEPENDS ${in_file} stringify
        OUTPUT ${out_file}
        COMMAND $<TARGET_FILE:stringify> ${basename} ${in_file} ${out_file}
    )
    list(APPEND glsl_sources ${out_file})
endforeach()


add_library(renderergl2)
target_sources(renderergl2
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_animation.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_backend.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_bsp.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_cmds.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_curve.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_dsa.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_extensions.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_extramath.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_fbo.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_flares.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_glsl.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_image.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_image_dds.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_init.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_light.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_main.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_marks.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_mesh.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_model.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_model_iqm.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_postprocess.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_scene.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_shade.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_shader.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_shade_calc.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_shadows.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_sky.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_subs.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_surface.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_vbo.c
        ${PROJECT_SOURCE_DIR}/code/renderergl2/tr_world.c
        ${glsl_sources}
)
target_compile_definitions(renderergl2 
    PUBLIC
)
target_link_libraries(renderergl2
    PRIVATE
        qcommon
        renderercommon
)


add_executable(client)
target_sources(client
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code/client/cl_avi.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_cgame.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_cin.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_console.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_curl.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_input.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_keys.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_main.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_net_chan.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_parse.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_scrn.c
        ${PROJECT_SOURCE_DIR}/code/client/cl_ui.c
        ${PROJECT_SOURCE_DIR}/code/client/libmumblelink.c
        ${PROJECT_SOURCE_DIR}/code/client/qal.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_adpcm.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_altivec.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_codec.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_codec_ogg.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_codec_opus.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_codec_wav.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_dma.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_main.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_mem.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_mix.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_openal.c
        ${PROJECT_SOURCE_DIR}/code/client/snd_wavelet.c
)
target_compile_definitions(client 
    PUBLIC
)
target_link_libraries(client
    PRIVATE
        qcommon
        botlib
        sdl
        servera
        renderergl2
        SDL2::SDL2main
)

