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

add_library(sys-cpp)
target_sources(sys-cpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code-cpp/sys/con_log.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/sys/con_win32.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/sys/sys_autoupdater.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/sys/sys_main.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/sys/sys_win32.cpp
)
target_link_libraries(sys-cpp
    PUBLIC
        SDL2::SDL2
    PRIVATE
        qcommon-cpp
)

add_library(asm-cpp OBJECT)
target_sources(asm-cpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code-cpp/asm/ftola.asm
        ${PROJECT_SOURCE_DIR}/code-cpp/asm/snapvector.asm
        ${PROJECT_SOURCE_DIR}/code-cpp/asm/vm_x86_64.asm
)
target_compile_definitions(asm-cpp
    PRIVATE
        idx64
)

add_library(qcommon-cpp)
target_sources(qcommon-cpp
    PRIVATE


        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/cmd.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/cm_load.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/cm_patch.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/cm_polylib.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/cm_test.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/cm_trace.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/common.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/cvar.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/files.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/huffman.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/ioapi.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/md4.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/md5.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/msg.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/net_chan.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/net_ip.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/puff.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/q_math.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/q_shared.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/unzip.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/vm.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/vm_interpreted.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/qcommon/vm_x86.cpp
)
target_compile_definitions(qcommon-cpp
    PUBLIC
        BOTLIB
        STANDALONE
        C_ONLY
)
target_link_libraries(qcommon-cpp
    PRIVATE
        ZLIB::ZLIB
        ws2_32
        asm-cpp
    PUBLIC
        sys-cpp
)

add_library(sdl-cpp)
target_sources(sdl-cpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code-cpp/sdl/sdl_gamma.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/sdl/sdl_glimp.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/sdl/sdl_input.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/sdl/sdl_snd.cpp
)
target_link_libraries(sdl-cpp
    PRIVATE
        qcommon-cpp
)

add_library(botlib-cpp)
target_sources(botlib-cpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_bspq3.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_cluster.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_debug.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_entity.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_file.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_main.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_move.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_optimize.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_reach.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_route.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_routealt.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_aas_sample.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_ai_char.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_ai_chat.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_ai_gen.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_ai_goal.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_ai_move.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_ai_weap.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_ai_weight.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_ea.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/be_interface.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/l_crc.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/l_libvar.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/l_log.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/l_memory.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/l_precomp.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/l_script.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/botlib/l_struct.cpp
)
target_link_libraries(botlib-cpp
    PRIVATE
        qcommon-cpp
)

add_library(server-cpp)
target_sources(server-cpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code-cpp/server/sv_bot.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/server/sv_ccmds.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/server/sv_client.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/server/sv_game.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/server/sv_init.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/server/sv_main.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/server/sv_net_chan.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/server/sv_snapshot.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/server/sv_world.cpp
)
target_link_libraries(server-cpp
    PRIVATE
        qcommon-cpp
)

add_library(renderercommon-cpp)
target_sources(renderercommon-cpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code-cpp/renderercommon/tr_font.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderercommon/tr_image_bmp.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderercommon/tr_image_jpg.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderercommon/tr_image_pcx.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderercommon/tr_image_png.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderercommon/tr_image_tga.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderercommon/tr_noise.cpp
)
target_link_libraries(renderercommon-cpp
    PRIVATE
        qcommon-cpp
        ${JPEG_LIBRARIES}
)
target_include_directories(renderercommon-cpp PRIVATE ${JPEG_INCLUDE_DIR})


add_executable(stringify-cpp)
target_sources(stringify-cpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/stringify.cpp
)
target_compile_features(stringify-cpp PRIVATE cxx_std_17)

set(glsl_shaders
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/bokeh_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/bokeh_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/calclevels4x_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/calclevels4x_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/depthblur_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/depthblur_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/dlight_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/dlight_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/down4x_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/down4x_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/fogpass_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/fogpass_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/generic_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/generic_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/lightall_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/lightall_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/pshadow_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/pshadow_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/shadowfill_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/shadowfill_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/shadowmask_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/shadowmask_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/ssao_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/ssao_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/texturecolor_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/texturecolor_vp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/tonemap_fp.glsl
    ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/glsl/tonemap_vp.glsl
)

foreach(in_file ${glsl_shaders})
    get_filename_component(basename ${in_file} NAME_WE)
    set(out_file ${PROJECT_BINARY_DIR}/gsls/${basename}.c)
    add_custom_command(
        DEPENDS ${in_file} stringify-cpp
        OUTPUT ${out_file}
        COMMAND $<TARGET_FILE:stringify-cpp> ${basename} ${in_file} ${out_file}
    )
    list(APPEND glsl_sources ${out_file})
endforeach()


add_library(renderergl2-cpp)
target_sources(renderergl2-cpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_animation.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_backend.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_bsp.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_cmds.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_curve.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_dsa.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_extensions.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_extramath.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_fbo.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_flares.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_glsl.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_image.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_image_dds.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_init.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_light.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_main.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_marks.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_mesh.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_model.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_model_iqm.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_postprocess.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_scene.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_shade.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_shader.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_shade_calc.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_shadows.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_sky.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_subs.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_surface.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_vbo.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/renderergl2/tr_world.cpp
        ${glsl_sources}
)
target_link_libraries(renderergl2-cpp
    PRIVATE
        qcommon-cpp
        renderercommon-cpp
)


add_executable(client-cpp)
target_sources(client-cpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_avi.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_cgame.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_cin.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_console.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_curl.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_input.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_keys.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_main.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_net_chan.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_parse.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_scrn.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/cl_ui.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/libmumblelink.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/qal.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_adpcm.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_altivec.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_codec.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_codec_ogg.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_codec_opus.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_codec_wav.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_dma.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_main.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_mem.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_mix.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_openal.cpp
        ${PROJECT_SOURCE_DIR}/code-cpp/client/snd_wavelet.cpp
)
target_link_libraries(client-cpp
    PRIVATE
        qcommon-cpp
        botlib-cpp
        sdl-cpp
        servera-cpp
        renderergl2-cpp
        SDL2::SDL2main
)

