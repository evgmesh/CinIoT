void text_reader_init(text_reader_ctx *ctc, const char *str){
    ctc->position = 0;
    ctc->text = str;
}
int text_reader_read(text_reader_ctx *ctx, char *buffer, int size){
    int cnt = 0;
    while(cnt < size - 1 && strlen(ctx->text) > ctx->position && buffer[cnt-1] != '\n'){
        buffer[cnt] = ctx->text[ctx->position];
        cnt++;
        ctx->position++;
    }
    buffer[cnt] = '\0';
    return cnt;
}